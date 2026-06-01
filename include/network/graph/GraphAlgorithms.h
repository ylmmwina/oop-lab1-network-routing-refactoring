#ifndef GRAPHALGORITHMS_H
#define GRAPHALGORITHMS_H

/**
 * @file GraphAlgorithms.h
 * @brief Generic graph algorithm abstractions and implementations.
 *
 * This file contains a common graph algorithm interface, BFS, DFS,
 * weighted edge representation, and Dijkstra shortest path algorithm.
 */

#include "network/graph/Graph.h"

#include <algorithm>
#include <functional>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

/**
 * @brief Abstract interface for graph traversal or processing algorithms.
 *
 * This interface demonstrates dynamic polymorphism for graph algorithms.
 *
 * @tparam TNode Type used for graph nodes.
 * @tparam TEdge Type used for graph edges.
 */
template <typename TNode, typename TEdge>
class GraphAlgorithm {
public:
    /**
     * @brief Runs the algorithm starting from a selected node.
     * @param g Graph to process.
     * @param start Start node.
     */
    virtual void run(const Graph<TNode, TEdge>& g, const TNode& start) = 0;

    /**
     * @brief Virtual destructor for safe polymorphic use.
     */
    virtual ~GraphAlgorithm() = default;
};

/**
 * @brief Breadth-first search algorithm.
 *
 * BFS visits graph nodes level by level using a queue.
 *
 * @tparam TNode Type used for graph nodes.
 * @tparam TEdge Type used for graph edges.
 */
template <typename TNode, typename TEdge>
class BFS : public GraphAlgorithm<TNode, TEdge> {
private:
    /**
     * @brief Set of already visited nodes.
     */
    std::set<TNode> visited;

public:
    /**
     * @brief Runs breadth-first search from the selected start node.
     * @param g Graph to traverse.
     * @param start Start node.
     */
    void run(const Graph<TNode, TEdge>& g, const TNode& start) override {
        std::queue<TNode> q;

        visited.clear();
        q.push(start);
        visited.insert(start);

        std::cout << "BFS: ";

        while (!q.empty()) {
            TNode node = q.front();
            q.pop();

            std::cout << node << " ";

            for (auto& neighbor : g.getNeighbors(node)) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        std::cout << "\n";
    }
};

/**
 * @brief Depth-first search algorithm.
 *
 * DFS visits graph nodes by exploring paths as deeply as possible first.
 * This implementation uses an explicit stack.
 *
 * @tparam TNode Type used for graph nodes.
 * @tparam TEdge Type used for graph edges.
 */
template <typename TNode, typename TEdge>
class DFS : public GraphAlgorithm<TNode, TEdge> {
private:
    /**
     * @brief Set of already visited nodes.
     */
    std::set<TNode> visited;

public:
    /**
     * @brief Runs depth-first search from the selected start node.
     * @param g Graph to traverse.
     * @param start Start node.
     */
    void run(const Graph<TNode, TEdge>& g, const TNode& start) override {
        std::stack<TNode> st;

        visited.clear();
        st.push(start);

        std::cout << "DFS: ";

        while (!st.empty()) {
            TNode node = st.top();
            st.pop();

            if (!visited.count(node)) {
                std::cout << node << " ";
                visited.insert(node);

                for (auto& neighbor : g.getNeighbors(node)) {
                    st.push(neighbor);
                }
            }
        }

        std::cout << "\n";
    }
};

/**
 * @brief Edge type for weighted graphs.
 *
 * Used by Dijkstra's algorithm. The weight usually represents distance,
 * cost, time, or another numeric metric.
 */
struct WeightedEdge {
    double weight{0.0};
};

/**
 * @brief Dijkstra shortest path algorithm.
 *
 * This class calculates shortest distances from a start node in a graph
 * whose edges are represented by WeightedEdge.
 *
 * @tparam TNode Type used for graph nodes.
 */
template <typename TNode>
class Dijkstra {
public:
    /**
     * @brief Shortest known distance from the start node to each node.
     */
    std::map<TNode, double> dist;

    /**
     * @brief Parent map used to reconstruct shortest paths.
     */
    std::map<TNode, TNode> parent;

    /**
     * @brief Runs Dijkstra's algorithm from a start node.
     *
     * If the start node does not exist, the method leaves distance data
     * initialized but does not calculate paths.
     *
     * @param g Weighted graph.
     * @param start Start node.
     */
    void run(const Graph<TNode, WeightedEdge>& g, const TNode& start) {
        dist.clear();
        parent.clear();

        for (auto& [u, _] : g.data()) {
            dist[u] = std::numeric_limits<double>::infinity();
        }

        if (!g.hasNode(start)) {
            return;
        }

        dist[start] = 0.0;

        using QItem = std::pair<double, TNode>;
        std::priority_queue<QItem, std::vector<QItem>, std::greater<QItem>> pq;

        pq.push({0.0, start});

        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();

            if (du != dist[u]) {
                continue;
            }

            auto it = g.data().find(u);
            if (it == g.data().end()) {
                continue;
            }

            for (auto& [v, w] : it->second) {
                double nd = du + w.weight;

                if (nd < dist[v]) {
                    dist[v] = nd;
                    parent[v] = u;
                    pq.push({nd, v});
                }
            }
        }
    }

    /**
     * @brief Reconstructs the shortest path from start to target.
     *
     * The method should be called after run().
     * If no path exists, an empty vector is returned.
     *
     * @param start Start node.
     * @param target Target node.
     * @return Ordered path from start to target, or an empty vector.
     */
    std::vector<TNode> getPathTo(const TNode& start, const TNode& target) const {
        std::vector<TNode> path;

        if (!dist.count(target) || dist.at(target) == std::numeric_limits<double>::infinity()) {
            return path;
        }

        TNode cur = target;

        while (cur != start) {
            path.push_back(cur);

            auto it = parent.find(cur);
            if (it == parent.end()) {
                path.clear();
                return path;
            }

            cur = it->second;
        }

        path.push_back(start);
        std::reverse(path.begin(), path.end());

        return path;
    }
};

#endif // GRAPHALGORITHMS_H