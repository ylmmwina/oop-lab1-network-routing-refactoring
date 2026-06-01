#ifndef NETWORK_H
#define NETWORK_H

/**
 * @file Network.h
 * @brief Domain model classes for the network routing simulator.
 *
 * This file contains the main network domain entities:
 * devices, links, and packets.
 */

#include <cstddef>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief Abstract base class for all network devices.
 *
 * Device stores common data shared by all devices in the simulated network:
 * numeric identifier and human-readable name.
 */
class Device {
protected:
    int id_;
    std::string name_;

public:
    /**
     * @brief Creates a device with an identifier and name.
     * @param id Numeric device identifier.
     * @param name Human-readable device name.
     */
    Device(int id, std::string name) : id_(id), name_(std::move(name)) {}

    /**
     * @brief Virtual destructor for safe polymorphic deletion.
     */
    virtual ~Device() = default;

    /**
     * @brief Returns the numeric device identifier.
     * @return Device identifier.
     */
    int id() const { return id_; }

    /**
     * @brief Returns the device name.
     * @return Constant reference to the device name.
     */
    const std::string& name() const { return name_; }

    /**
     * @brief Returns the concrete type of the device.
     * @return Device type as a string.
     */
    virtual std::string kind() const = 0;
};

/**
 * @brief Abstract intermediate class for network infrastructure devices.
 *
 * NetworkDevice extends Device with a management interface field.
 * Routers and switches inherit from this class.
 */
class NetworkDevice : public Device {
protected:
    std::string mgmtInterface_;

public:
    /**
     * @brief Creates a network device.
     * @param id Numeric device identifier.
     * @param name Human-readable device name.
     * @param mgmt Management interface name.
     */
    NetworkDevice(int id, std::string name, std::string mgmt = "")
        : Device(id, std::move(name)), mgmtInterface_(std::move(mgmt)) {}

    /**
     * @brief Virtual destructor for safe polymorphic use.
     */
    virtual ~NetworkDevice() = default;

    /**
     * @brief Returns the management interface name.
     * @return Constant reference to the management interface.
     */
    const std::string& mgmtInterface() const { return mgmtInterface_; }

    /**
     * @brief Updates the management interface name.
     * @param s New management interface name.
     */
    void setMgmtInterface(std::string s) { mgmtInterface_ = std::move(s); }
};

/**
 * @brief Router device in the simulated network.
 *
 * Router represents a network device that can participate in packet routing.
 */
class Router : public NetworkDevice {
    std::string routingHint_;

public:
    /**
     * @brief Creates a router.
     * @param id Numeric router identifier.
     * @param name Router name.
     * @param mgmt Management interface name.
     */
    Router(int id, std::string name, std::string mgmt = "")
        : NetworkDevice(id, std::move(name), std::move(mgmt)) {}

    /**
     * @brief Returns the concrete device type.
     * @return The string "Router".
     */
    std::string kind() const override { return "Router"; }
};

/**
 * @brief Switch device in the simulated network.
 *
 * Switch represents a network device used to connect other devices.
 */
class Switch : public NetworkDevice {
public:
    /**
     * @brief Creates a switch.
     * @param id Numeric switch identifier.
     * @param name Switch name.
     * @param mgmt Management interface name.
     */
    Switch(int id, std::string name, std::string mgmt = "")
        : NetworkDevice(id, std::move(name), std::move(mgmt)) {}

    /**
     * @brief Returns the concrete device type.
     * @return The string "Switch".
     */
    std::string kind() const override { return "Switch"; }
};

/**
 * @brief End host in the simulated network.
 *
 * Host is an endpoint device that can be used as a packet source or destination.
 */
class Host : public Device {
    std::string address_;

public:
    /**
     * @brief Creates a host.
     * @param id Numeric host identifier.
     * @param name Host name.
     * @param addr Network address.
     */
    Host(int id, std::string name, std::string addr)
        : Device(id, std::move(name)), address_(std::move(addr)) {}

    /**
     * @brief Returns the host address.
     * @return Constant reference to the address string.
     */
    const std::string& address() const { return address_; }

    /**
     * @brief Returns the concrete device type.
     * @return The string "Host".
     */
    std::string kind() const override { return "Host"; }
};

/**
 * @brief Network link between two devices.
 *
 * Link stores simplified physical or logical connection parameters:
 * latency, bandwidth, and reliability.
 */
struct Link {
    double latencyMs{1.0};
    double bandwidthMbps{100.0};
    double reliability{0.999};

    /**
     * @brief Calculates transmission cost for a payload.
     *
     * The cost is represented as approximate transmission time in seconds.
     * It includes link latency and payload transmission time.
     *
     * @param bytes Payload size in bytes.
     * @return Estimated transmission time in seconds.
     */
    double costForBytes(std::size_t bytes) const {
        double secondsLatency = latencyMs / 1000.0;
        double secondsPayload = (bandwidthMbps > 0.0)
            ? (static_cast<double>(bytes) / (bandwidthMbps * 1'000'000.0))
            : 1e9;

        return secondsLatency + secondsPayload;
    }
};

/**
 * @brief Packet transmitted through the simulated network.
 *
 * Packet stores source, destination, time-to-live value, payload size,
 * and the list of visited nodes.
 */
class Packet {
    std::string source_;
    std::string destination_;
    int ttl_{8};
    std::size_t sizeBytes_{512};
    std::vector<std::string> hops_;

public:
    /**
     * @brief Creates a packet.
     * @param src Source device name.
     * @param dst Destination device name.
     * @param ttl Initial time-to-live value.
     * @param size Payload size in bytes.
     */
    Packet(std::string src, std::string dst, int ttl = 8, std::size_t size = 512)
        : source_(std::move(src)),
          destination_(std::move(dst)),
          ttl_(ttl),
          sizeBytes_(size) {}

    /**
     * @brief Returns the packet source.
     * @return Constant reference to source device name.
     */
    const std::string& src() const { return source_; }

    /**
     * @brief Returns the packet destination.
     * @return Constant reference to destination device name.
     */
    const std::string& dst() const { return destination_; }

    /**
     * @brief Returns the current TTL value.
     * @return Current time-to-live value.
     */
    int ttl() const { return ttl_; }

    /**
     * @brief Returns the packet size.
     * @return Packet size in bytes.
     */
    std::size_t size() const { return sizeBytes_; }

    /**
     * @brief Returns the list of visited nodes.
     * @return Constant reference to hop history.
     */
    const std::vector<std::string>& hops() const { return hops_; }

    /**
     * @brief Decreases TTL by one.
     */
    void decTTL() { --ttl_; }

    /**
     * @brief Adds a node name to the packet hop history.
     * @param nodeName Name of the visited node.
     */
    void addHop(const std::string& nodeName) { hops_.push_back(nodeName); }
};

#endif // NETWORK_H