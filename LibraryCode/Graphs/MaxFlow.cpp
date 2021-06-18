//
// Created by Jonny Keane on 6/17/21.
//
#include <bits/stdc++.h>
using namespace std;

using namespace std;

/// Maximum flow classes
namespace MaxFlow {
    /// A node in a flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class Node;
    /// A connection in a flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class Connection;
    /// A flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class FlowGraph;

    /// Enumerates the sink and source nodes
    enum flowGraphNodes {
        SOURCE = -1,
        SINK = -2
    };

    /// A node in a flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class Node {
    public:
        /// The connections and where they lead (mapped for O(logn) indexing
        map<int, Connection<W>*> conns;
    };

    /// A connection in a flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class Connection {
    public:
        int from;
        int to;
        W fwCap;
        W bwCap;

        /// Initializes connection
        /// \param from Index of from node
        /// \param to Index of to node
        /// \param fwCap Capacity going forwards on connection
        /// \param bwCap Capacity going backwards on connection
        Connection(int from, int to, W fwCap, W bwCap) :
                from(from), to(to), fwCap(fwCap), bwCap(bwCap) {}

        /// Send flow down a connection
        /// \param flow The amount of flow to send
        /// \param from_ Where the flow is originating from
        void sendFlow(W flow, int from_) {
            if (from_ == from) {
                fwCap -= flow;
                bwCap += flow;
            } else {
                fwCap += flow;
                bwCap -= flow;
            }
        }

        /// The to node for a given direction
        /// \param from_ The from node
        /// \return The to node for a given direction
        int to_(int from_) {
            return from_ == from ? to : from;
        }

        /// The forward capacity for a given direction
        /// \param from_ The from node
        /// \return The forward capacity for a given direction
        W fwCap_(int from_) {
            return from_ == from ? fwCap : bwCap;
        }
    };

    /// A flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class FlowGraph {
    public:
        map<int, Node<W>> nodes;

        /// Initializes just the source and sink nodes
        FlowGraph() {
            nodes[SOURCE] = Node<W>();
            nodes[SINK] = Node<W>();
        }

        /// Initializes the source, sink, and a range of nodes
        /// \param start
        /// \param end
        FlowGraph(int start, int end) : FlowGraph() {
            for (int i = start; i <= end; ++i) {
                nodes[i] = Node<W>();
            }
        }

        /// Adds connection between nodes
        /// \param from From node
        /// \param to To node
        /// \param fwCap Forward capacity
        /// \param bwCap Backward capacity
        void addConnection(int from, int to, W fwCap, W bwCap) {
            auto* conn = new Connection<W>(from, to, fwCap, bwCap);
            nodes[from].conns[to] = conn;
            nodes[to].conns[from] = conn;
        }

        /// Returns the maximum flow of a flow graph
        /// \return The maximum flow of a graph
        int fordFulkerson() {
            W maxFlow = 0;
            W pathFlow = bfs();
            while (pathFlow != -1) {
                maxFlow += pathFlow;
                sendFlow(pathFlow);
                pathFlow = bfs();
            }
            return maxFlow;
        }

    private:
        map<int, int> parents;
        /// Sends flow down the path found by the bfs
        /// \param pathMaxFlow The path flow found
        void sendFlow(W pathMaxFlow) {
            int curr = SINK;
            while (curr != SOURCE) {
                int temp = parents[curr];
                nodes[temp].conns[curr]->sendFlow(pathMaxFlow, temp);
                curr = temp;
            }
        }

        /// Searches for sink starting from source
        /// \return The flow for a path source to sink (-1 if fails)
        W bfs() {
            parents.clear();
            set<int> visited;
            queue<pair<pair<int, int>, Connection<W>*>> q;
            visited.insert(SOURCE);
            for (auto conn: nodes[SOURCE].conns) {
                if (conn.second->fwCap_(SOURCE) > 0) {
                    q.push(make_pair(make_pair(SOURCE, conn.second->fwCap_(SOURCE)), conn.second));
                    parents[conn.second->to_(SOURCE)] = SOURCE;
                    visited.insert(conn.second->to_(SOURCE));
                }
            }
            while (!q.empty()) {
                auto top = q.front();
                q.pop();
                // --- defining from and to ---
                int from = top.first.first;
                W maxFlow = top.first.second;
                Connection<W>* conn = top.second;
                int to = conn->to_(from);
                // ----------------------------
                if (to == SINK) return maxFlow;
                for (auto nextConn: nodes[to].conns) {
                    if (visited.count(nextConn.second->to_(to)) == 0 && nextConn.second->fwCap_(to) > 0) {
                        visited.insert(nextConn.second->to_(to));
                        parents[nextConn.second->to_(to)] = to;
                        q.push(make_pair(make_pair(to, min(maxFlow, nextConn.second->fwCap_(to))), nextConn.second));
                    }
                }
            }
            return -1;
        }
    };
}

