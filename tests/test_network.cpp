#include "../third_party/googletest/googletest/include/gtest/gtest.h"

#include "network/graph/Graph.h"
#include "network/graph/GraphAlgorithms.h"
#include "network/model/Network.h"
#include "network/simulator/NetworkSimulator.h"

#include <memory>

// ---------- Hierarchy / polymorphism tests ----------
TEST(HierarchyTest, KindAndDynamicCast) {
    auto r = std::make_unique<Router>(1, "R1", "mgmt0");
    auto s = std::make_unique<Switch>(2, "S1", "mgmt1");
    auto h = std::make_unique<Host>(3, "H1", "10.0.0.1");

    EXPECT_EQ(r->kind(), "Router");
    EXPECT_EQ(s->kind(), "Switch");
    EXPECT_EQ(h->kind(), "Host");

    // Router повинен каститись до NetworkDevice
    NetworkDevice* nd = dynamic_cast<NetworkDevice*>(r.get());
    ASSERT_NE(nd, nullptr);
    EXPECT_EQ(nd->mgmtInterface(), "mgmt0");

    // Host — у нас варіант A: Host не є NetworkDevice
    NetworkDevice* nd2 = dynamic_cast<NetworkDevice*>(h.get());
    EXPECT_EQ(nd2, nullptr);
}

// ---------- Graph + Dijkstra tests ----------
TEST(GraphDijkstraTest, BasicPathAndDistance) {
    Graph<std::string, WeightedEdge> wg(true);
    wg.addNode("A");
    wg.addNode("B");
    wg.addNode("C");

    wg.addEdge("A", "B", WeightedEdge{5.0});
    wg.addEdge("B", "C", WeightedEdge{2.0});
    wg.addEdge("A", "C", WeightedEdge{9.0});

    Dijkstra<std::string> dj;
    dj.run(wg, "A");
    auto path = dj.getPathTo("A", "C");

    ASSERT_EQ(path.size(), 3);
    EXPECT_EQ(path[0], "A");
    EXPECT_EQ(path[1], "B");
    EXPECT_EQ(path[2], "C");
    EXPECT_NEAR(dj.dist.at("C"), 7.0, 1e-9);
}

// ---------- NetworkSimulator registry tests ----------
TEST(NetworkSimulatorTest, DeviceRegistryTracksAddedDevices) {
    NetworkSimulator sim;

    EXPECT_EQ(sim.deviceCount(), 0u);
    EXPECT_FALSE(sim.hasDevice("R1"));

    sim.addDevice(std::make_unique<Router>(1, "R1"));
    sim.addDevice(std::make_unique<Switch>(2, "S1"));
    sim.addDevice(std::make_unique<Host>(3, "H1", "10.0.0.1"));

    EXPECT_EQ(sim.deviceCount(), 3u);
    EXPECT_TRUE(sim.hasDevice("R1"));
    EXPECT_TRUE(sim.hasDevice("S1"));
    EXPECT_TRUE(sim.hasDevice("H1"));
    EXPECT_FALSE(sim.hasDevice("Unknown"));
}

// ---------- NetworkSimulator basic flow test ----------
TEST(NetworkSimulatorTest, BuildDemoRouteAndSend) {
    NetworkSimulator sim;
    sim.addDevice(std::make_unique<Router>(1, "R1"));
    sim.addDevice(std::make_unique<Switch>(2, "S1"));
    sim.addDevice(std::make_unique<Host>(3, "H1", "10.0.0.1"));
    sim.addDevice(std::make_unique<Host>(4, "H2", "10.0.0.2"));

    sim.connect("R1", "S1", Link{0.5, 100.0, 0.999});
    sim.connect("S1", "H1", Link{1.0, 100.0, 0.999});
    sim.connect("R1", "H2", Link{3.0, 20.0, 0.98});

    DijkstraRouting algo;
    Packet pkt("H1", "H2", 8, 1500);
    auto route = sim.findRoute(algo, "H1", "H2", pkt.size());

    // перевіряємо, що маршрут знайдено (мінімум два вузли)
    ASSERT_GE(route.size(), 2u);

    double t = sim.sendPacket(route, pkt);

    EXPECT_GT(t, 0.0);
    EXPECT_LT(pkt.ttl(), 8); // TTL зменшився
}
// ---------- NetworkSimulator error handling tests ----------
TEST(NetworkSimulatorTest, AddNullDeviceThrowsException) {
    NetworkSimulator sim;

    EXPECT_THROW(
        sim.addDevice(nullptr),
        std::runtime_error
    );
}

TEST(NetworkSimulatorTest, ConnectUnknownDeviceThrowsException) {
    NetworkSimulator sim;

    sim.addDevice(std::make_unique<Router>(1, "R1"));

    EXPECT_THROW(
        sim.connect("R1", "Unknown", Link{}),
        std::runtime_error
    );

    EXPECT_THROW(
        sim.connect("Unknown", "R1", Link{}),
        std::runtime_error
    );
}