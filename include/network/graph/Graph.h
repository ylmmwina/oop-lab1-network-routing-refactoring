#ifndef GRAPH_H
#define GRAPH_H

/**
 * @file Graph.h
 * @brief Generic graph data structure for the network routing simulator.
 *
 * This file contains a template-based graph implementation that can be used
 * with different node and edge types. In this project it is used to represent
 * network topology.
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>

/**
 * @brief Generic adjacency-list graph.
 *
 * The graph stores nodes of type TNode and edge data of type TEdge.
 * It can work as either a directed or undirected graph.
 *
 * @tparam TNode Type used for graph nodes.
 * @tparam TEdge Type used for edge payload data.
 */
template <typename TNode, typename TEdge>
class Graph {
private:
    /**
     * @brief Adjacency list.
     *
     * For each node, stores a list of pairs:
     * neighbor node and edge data.
     */
    std::map<TNode, std::vector<std::pair<TNode, TEdge>>> adjacency;

    /**
     * @brief Defines whether the graph is directed.
     */
    bool directed_ = true;

public:
    /**
     * @brief Creates a graph.
     * @param directed If true, graph is directed. If false, graph is undirected.
     */
    explicit Graph(bool directed = true) : directed_(directed) {}

    /**
     * @brief Adds a node to the graph.
     *
     * If the node already exists, the graph remains unchanged.
     *
     * @param node Node to add.
     */
    void addNode(const TNode& node) {
        adjacency[node];
    }

    /**
     * @brief Adds an edge between two nodes.
     *
     * If the graph is undirected, a reverse edge is also added.
     * Missing nodes are created automatically.
     *
     * @param from Source node.
     * @param to Destination node.
     * @param edge Edge data.
     */
    void addEdge(const TNode& from, const TNode& to, const TEdge& edge) {
        addNode(from);
        addNode(to);

        adjacency[from].push_back({to, edge});

        if (!directed_) {
            adjacency[to].push_back({from, edge});
        }
    }

    /**
     * @brief Removes a node and all edges pointing to it.
     * @param node Node to remove.
     */
    void removeNode(const TNode& node) {
        adjacency.erase(node);

        for (auto& [u, neighbors] : adjacency) {
            neighbors.erase(
                std::remove_if(
                    neighbors.begin(),
                    neighbors.end(),
                    [&](auto& pair) { return pair.first == node; }
                ),
                neighbors.end()
            );
        }
    }

    /**
     * @brief Removes an edge between two nodes.
     *
     * If the graph is undirected, the reverse edge is also removed.
     *
     * @param from Source node.
     * @param to Destination node.
     */
    void removeEdge(const TNode& from, const TNode& to) {
        if (auto it = adjacency.find(from); it != adjacency.end()) {
            auto& neighbors = it->second;

            neighbors.erase(
                std::remove_if(
                    neighbors.begin(),
                    neighbors.end(),
                    [&](auto& p) { return p.first == to; }
                ),
                neighbors.end()
            );
        }

        if (!directed_) {
            if (auto jt = adjacency.find(to); jt != adjacency.end()) {
                auto& rev = jt->second;

                rev.erase(
                    std::remove_if(
                        rev.begin(),
                        rev.end(),
                        [&](auto& p) { return p.first == from; }
                    ),
                    rev.end()
                );
            }
        }
    }

    /**
     * @brief Returns neighboring nodes for a given node.
     *
     * The method returns only node values, not edge data.
     *
     * @param node Node whose neighbors should be returned.
     * @return Vector of neighboring nodes.
     */
    std::vector<TNode> getNeighbors(const TNode& node) const {
        std::vector<TNode> result;

        if (auto it = adjacency.find(node); it != adjacency.end()) {
            result.reserve(it->second.size());

            for (auto& pair : it->second) {
                result.push_back(pair.first);
            }
        }

        return result;
    }

    /**
     * @brief Prints a simple text representation of the graph.
     *
     * This method is intended for debugging and demonstration output.
     */
    void printGraph() const {
        for (auto& [node, neighbors] : adjacency) {
            std::cout << node << " -> ";

            for (auto& [n, e] : neighbors) {
                std::cout << "(" << n << ", edge=" << e << ") ";
            }

            std::cout << "\n";
        }
    }

    /**
     * @brief Removes all nodes and edges from the graph.
     */
    void clear() {
        adjacency.clear();
    }

    /**
     * @brief Returns the number of nodes in the graph.
     * @return Number of nodes.
     */
    std::size_t size() const {
        return adjacency.size();
    }

    /**
     * @brief Checks whether a node exists in the graph.
     * @param node Node to check.
     * @return true if the node exists, otherwise false.
     */
    bool hasNode(const TNode& node) const {
        return adjacency.count(node) != 0;
    }

    /**
     * @brief Provides read-only access to raw adjacency data.
     *
     * This method is used by graph algorithms and routing logic.
     *
     * @return Constant reference to the adjacency map.
     */
    const std::map<TNode, std::vector<std::pair<TNode, TEdge>>>& data() const {
        return adjacency;
    }
};

#endif // GRAPH_H