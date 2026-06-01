#ifndef NETWORKSIMULATOR_H
#define NETWORKSIMULATOR_H

/**
 * @file NetworkSimulator.h
 * @brief Routing algorithm abstractions and network simulator implementation.
 *
 * This file contains the routing strategy interface, Dijkstra-based routing
 * implementation, and the main NetworkSimulator class.
 */

#include "network/graph/Graph.h"
#include "network/graph/GraphAlgorithms.h"
#include "network/model/Network.h"

#include <fstream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <stdexcept>

/**
 * @brief Abstract interface for routing algorithms.
 *
 * RoutingAlgorithm represents the Strategy pattern. NetworkSimulator can use
 * any concrete routing algorithm through this common interface.
 */
class RoutingAlgorithm {
public:
    /**
     * @brief Virtual destructor for safe polymorphic use.
     */
    virtual ~RoutingAlgorithm() = default;

    /**
     * @brief Calculates a route between two network nodes.
     * @param g Network topology graph.
     * @param src Source node name.
     * @param dst Destination node name.
     * @param payloadBytes Packet payload size in bytes.
     * @return Ordered list of node names representing the route.
     */
    virtual std::vector<std::string> route(
        const Graph<std::string, Link>& g,
        const std::string& src,
        const std::string& dst,
        std::size_t payloadBytes) = 0;
};

/**
 * @brief Routing algorithm implementation based on Dijkstra's algorithm.
 *
 * DijkstraRouting converts the network graph with Link objects into a weighted
 * graph where each edge weight is calculated as transmission cost for a payload.
 */
class DijkstraRouting : public RoutingAlgorithm {
public:
    /**
     * @brief Calculates the shortest route using Dijkstra's algorithm.
     * @param g Network topology graph.
     * @param src Source node name.
     * @param dst Destination node name.
     * @param payloadBytes Packet payload size in bytes.
     * @return Ordered list of node names representing the route.
     */
    std::vector<std::string> route(
        const Graph<std::string, Link>& g,
        const std::string& src,
        const std::string& dst,
        std::size_t payloadBytes) override
    {
        Graph<std::string, WeightedEdge> wg(true);

        for (auto& [u, _] : g.data()) {
            wg.addNode(u);
        }

        for (auto& [u, vec] : g.data()) {
            for (auto& [v, link] : vec) {
                double w = link.costForBytes(payloadBytes);
                wg.addEdge(u, v, WeightedEdge{w});
            }
        }

        Dijkstra<std::string> dj;
        dj.run(wg, src);
        return dj.getPathTo(src, dst);
    }
};

/**
 * @brief Main class for building and simulating a network topology.
 *
 * NetworkSimulator owns registered devices, stores the topology graph,
 * connects devices with links, calculates routes, sends packets, and can
 * save or load topology data.
 *
 * Device ownership is represented with std::unique_ptr<Device>, so the
 * simulator clearly owns all devices registered through addDevice().
 */
class NetworkSimulator {
private:
    Graph<std::string, Link> graph_;
    std::map<std::string, std::unique_ptr<Device>> devices_;

public:
    /**
     * @brief Creates an empty network simulator.
     */
    NetworkSimulator() = default;

    /**
     * @brief Default destructor.
     *
     * Devices are cleaned automatically by std::unique_ptr.
     */
    ~NetworkSimulator() = default;

    /**
     * @brief Copying is disabled because the simulator owns devices.
     */
    NetworkSimulator(const NetworkSimulator&) = delete;

    /**
     * @brief Copy assignment is disabled because the simulator owns devices.
     */
    NetworkSimulator& operator=(const NetworkSimulator&) = delete;

    /**
     * @brief Move construction is allowed.
     */
    NetworkSimulator(NetworkSimulator&&) noexcept = default;

    /**
     * @brief Move assignment is allowed.
     */
    NetworkSimulator& operator=(NetworkSimulator&&) noexcept = default;

    /**
     * @brief Checks whether a device with the given name is registered.
     * @param name Device name.
     * @return true if the device exists, otherwise false.
     */
    bool hasDevice(const std::string& name) const {
        return devices_.contains(name);
    }

    /**
     * @brief Returns the number of registered devices.
     * @return Number of devices in the simulator.
     */
    std::size_t deviceCount() const {
        return devices_.size();
    }

    /**
     * @brief Registers a device in the network.
     *
     * The simulator takes ownership of the provided device.
     *
     * @param device Unique pointer to a device.
     * @throws std::runtime_error If the provided pointer is null.
     */
    void addDevice(std::unique_ptr<Device> device) {
        if (!device) {
            throw std::runtime_error("Null device");
        }

        std::string name = device->name();
        graph_.addNode(name);
        devices_[name] = std::move(device);
    }

    /**
     * @brief Connects two registered devices with a link.
     * @param a First device name.
     * @param b Second device name.
     * @param link Link parameters.
     * @param bidir If true, creates a bidirectional connection.
     * @throws std::runtime_error If one of the devices is unknown.
     */
    void connect(const std::string& a, const std::string& b, const Link& link, bool bidir = true) {
        if (!graph_.hasNode(a) || !graph_.hasNode(b)) {
            throw std::runtime_error("Unknown node in connect()");
        }

        graph_.addEdge(a, b, link);

        if (bidir) {
            graph_.addEdge(b, a, link);
        }
    }

    /**
     * @brief Builds a predefined demonstration topology.
     *
     * The demo topology contains router R1, switch S1, hosts H1 and H2,
     * and several weighted links between them.
     */
    void buildDemo() {
        addDevice(std::make_unique<Router>(1, "R1", "eth0"));
        addDevice(std::make_unique<Switch>(2, "S1", "mgmt0"));
        addDevice(std::make_unique<Host>(3, "H1", "10.0.0.1"));
        addDevice(std::make_unique<Host>(4, "H2", "10.0.0.2"));

        connect("R1", "S1", Link{0.5, 100.0, 0.999});
        connect("S1", "H1", Link{1.0, 100.0, 0.999});
        connect("R1", "H2", Link{3.0, 20.0, 0.98});
    }

    /**
     * @brief Finds a route between two devices using a routing algorithm.
     * @param algo Routing algorithm strategy.
     * @param src Source node name.
     * @param dst Destination node name.
     * @param payloadBytes Packet payload size in bytes.
     * @return Ordered list of node names representing the route.
     */
    std::vector<std::string> findRoute(
        RoutingAlgorithm& algo,
        const std::string& src,
        const std::string& dst,
        std::size_t payloadBytes) const
    {
        return algo.route(graph_, src, dst, payloadBytes);
    }

    /**
     * @brief Sends a packet along a calculated route.
     *
     * The method decreases packet TTL, records visited nodes, and accumulates
     * estimated transmission time based on link costs.
     *
     * @param path Ordered list of node names.
     * @param pkt Packet to send.
     * @return Total estimated transmission time in seconds.
     */
    double sendPacket(const std::vector<std::string>& path, Packet& pkt) const {
        if (path.size() < 2) {
            return 0.0;
        }

        double totalSeconds = 0.0;
        pkt.addHop(path.front());

        for (std::size_t i = 1; i < path.size(); ++i) {
            if (pkt.ttl() <= 0) {
                break;
            }

            const std::string& u = path[i - 1];
            const std::string& v = path[i];

            double edgeCost = 1e9;

            auto it = graph_.data().find(u);
            if (it != graph_.data().end()) {
                for (auto& [to, link] : it->second) {
                    if (to == v) {
                        edgeCost = link.costForBytes(pkt.size());
                        break;
                    }
                }
            }

            totalSeconds += edgeCost;
            pkt.decTTL();
            pkt.addHop(v);
        }

        return totalSeconds;
    }

    /**
     * @brief Saves the current topology to a text file.
     * @param filename Output file path.
     * @throws std::runtime_error If the file cannot be opened.
     */
    void saveTopology(const std::string& filename) const {
        std::ofstream out(filename);

        if (!out) {
            throw std::runtime_error("Cannot open file for writing");
        }

        out << "NODES:\n";

        for (auto& [name, dev] : devices_) {
            out << " " << name << " " << dev->kind() << "\n";
        }

        out << "EDGES:\n";

        for (auto& [u, vec] : graph_.data()) {
            for (auto& [v, link] : vec) {
                out << " " << u << " " << v << " "
                    << link.latencyMs << " "
                    << link.bandwidthMbps << " "
                    << link.reliability << "\n";
            }
        }
    }

    /**
     * @brief Loads topology from a text file.
     * @param filename Input file path.
     * @throws std::runtime_error If the file cannot be opened.
     */
    void loadTopology(const std::string& filename) {
        devices_.clear();
        graph_.clear();

        std::ifstream in(filename);

        if (!in) {
            throw std::runtime_error("Cannot open file for reading");
        }

        std::string line;
        enum Section { NONE, NODES, EDGES } sect = NONE;

        while (std::getline(in, line)) {
            if (line == "NODES:") {
                sect = NODES;
                continue;
            }

            if (line == "EDGES:") {
                sect = EDGES;
                continue;
            }

            if (line.empty() || line[0] == '#') {
                continue;
            }

            std::istringstream iss(line);

            if (sect == NODES) {
                std::string name;
                std::string kind;

                iss >> name >> kind;

                int id = static_cast<int>(devices_.size()) + 1;

                if (kind == "Router") {
                    addDevice(std::make_unique<Router>(id, name));
                } else if (kind == "Switch") {
                    addDevice(std::make_unique<Switch>(id, name));
                } else if (kind == "Host") {
                    addDevice(std::make_unique<Host>(id, name, "0.0.0.0"));
                } else {
                    addDevice(std::make_unique<Router>(id, name));
                }
            } else if (sect == EDGES) {
                std::string u;
                std::string v;
                double lat;
                double bw;
                double rel;

                iss >> u >> v >> lat >> bw >> rel;
                connect(u, v, Link{lat, bw, rel}, false);
            }
        }
    }

    /**
     * @brief Prints all registered devices to the standard output.
     */
    void printDevices() const {
        std::cout << "Devices:\n";

        for (auto& [name, dev] : devices_) {
            std::cout << "  " << std::left << std::setw(6) << name
                      << " : " << dev->kind() << "\n";
        }
    }
};

#endif // NETWORKSIMULATOR_H