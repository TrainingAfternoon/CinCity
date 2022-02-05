//
// Created by Jonny Keane on 8/10/21.
//

// strongly polynomial max flow with a run time of O(V^2E)
// better because usually many more edges than there are vertices
// for bipartite matching -> O(sqrt(V)E)

// some of the theory: (https://www.youtube.com/watch?v=M6cm8UeeziI)
//  - constantly making progress
//  - guide augmenting paths from the source to the sink with a level graph
//      - in a level graph, track levels created from BFS
//          - in flow seeking, you only can go move levels L -> L+1
//              * might get tough in the sense that you may have to redefine the levels every time?
//                  -> only rebuild when a blocking flow has been reached
//              - only use other edges if a reroute is required
//      - conduct multiple DFS's that lead you right to sink with your level graph
//      - once hit blocking flow, use sum over bottleneck values to create max flow
//          - blocking flow is when no path source to sink cannot be found because too many edges are saturated
// - pitfall -> hitting same dead ends in cycles
//      - resolve -> remove dead ends on the fly (so only encountered once)

#include "bits/stdc++.h"
using namespace std;

namespace dinics_algorithm {
    enum flow_graph_nodes {
        SOURCE = -1,
        SINK = -2,
        UNKNOWN = -3
    };

    template<typename W>
    class node;

    template<typename W>
    class connection;

    template<typename W>
    class level_graph;

    template<typename W>
    class node {
    public:
        int level;
        map<int, connection<W>*> conns;
        node() : level(UNKNOWN) {}
        node(int level) : level(level) {}
    };

    template<typename W>
    class connection {
    public:
        connection(int from_, int to_, W fw_cap_, W bw_cap_) :
            from_(from_), to_(to_), fw_cap_(fw_cap_), bw_cap_(bw_cap_) {
        }

        void send_flow(W flow, int from) {
            if (from_ == from) {
                fw_cap_ -= flow;
                bw_cap_ += flow;
            } else {
                fw_cap_ += flow;
                bw_cap_ -= flow;
            }
        }

        int to(int from) {
            return from_ == from ? to_ : from_;
        }

        W fw_cap(int from) {
            return from_ == from ? fw_cap_ : bw_cap_;
        }

        bool is_direction_in_level_graph(int from) {
            return from_ = from ? fw_cap_ > 0 : bw_cap_ > 0;
        }

    private:
        int from_;
        int to_;
        W fw_cap_;
        W bw_cap_;
    };

    template<typename W>
    class level_graph {
    public:
        /// Map of all node IDs to their respective nodes
        unordered_map<int, node<W>> node_ids;

        /// Creates a level flow graph and initializes source and sink
        level_graph() {
            add_node_(SOURCE, SOURCE);
            add_node_(SINK, SINK);
        }

        /// Adds node to the graph
        void add_node(int id) {
            add_node_(id, UNKNOWN);
        }

        /// Adds flow connection to the graph
        void add_connection(int from, int to, W fw_cap, W bw_cap) {
            auto * conn = new connection<W>(from, to, fw_cap, bw_cap);
            node_ids[from].conns[to] = &conn;
            node_ids[to].conns[from] = &conn;
            cout << &node_ids[from].conns[to] << " " << &node_ids[to].conns[from] << endl;
        }

        /// Calculates max flow according to Dinic's Algorithm
        W dinics_max_flow() {
            W max_flow = 0;
            while (init_level_graph_bfs_()) {
                W flow_found = flow_find_dfs_();
                while (flow_found != -1) {
                    cout << flow_found << endl;
                    send_flow_(flow_found);
                    max_flow += flow_found;
                    flow_found = flow_find_dfs_();
                }
            }
            return max_flow;
        }

    private:
        /// Parents of given nodes discovered by DFS
        unordered_map<int, int> parents_;

        /// Adds a node with a current ID and level
        void add_node_(int id, int level) {
            node_ids[id] = node<W>(level);
        }

        /// Turns the current flow graph into a level graph
        bool init_level_graph_bfs_() {
            unordered_set<int> visited;
            queue<pair<int, int>> bfs_q; // {node, level}
            bfs_q.push(make_pair(SOURCE, 0));
            while (!bfs_q.empty()) {
                auto top = bfs_q.front();
                node<W> top_node = node_ids[top.first];
                bfs_q.pop();
                visited.insert(top.first);
                if (top.first == SINK) continue;
                if (top.second != 0) {
                    top_node.level = top.second;
//                    cout << top.first << " " << top.second << endl;
                }
                for (auto conn: top_node.conns) {
                    if (visited.count(conn.first) != 0 || !conn.second->is_direction_in_level_graph(top.first)) continue;
                    bfs_q.push(make_pair(conn.first, top.second + 1));
                }
            }
            return visited.count(SINK) != 0;
        }

        /// Finds a flow from SOURCE to SINK through DFS or returns -1 if not possible
        W flow_find_dfs_() {
            unordered_set<int> visited;
            visited.insert(SOURCE);
            parents_.clear();
            stack<pair<int, int>> dfs_stack; // {node, min_flow_on_path}
            dfs_stack.push(make_pair(SOURCE, INT_MAX));
            while (!dfs_stack.empty()) {
                auto top = dfs_stack.top();
                dfs_stack.pop();
                if (top.first == SINK) return top.second;
                visited.insert(top.first);
//                            cout << top.first << " reached with cap " << top.second << endl;
//                for (auto conn: node_ids[top.first].conns) {
//                    cout << SOURCE << " " << conn.first << endl;
//                }
                for (auto conn: node_ids[top.first].conns) {
//                    cout << conn.first << endl;
                    if (visited.count(conn.first) != 0 || conn.second->fw_cap(top.first) == 0) continue;
//                    cout << top.first << "->" << conn.first << endl;
                    parents_[conn.first] = top.first;
                    dfs_stack.push(make_pair(conn.first, min(conn.second->fw_cap(top.first), top.second)));
                }
            }
            return -1;
        }

        /// Sends flow and augments the path
        void send_flow_(W path_max_flow) {
            int curr = SINK;
            while (curr != SOURCE) {
                int temp = parents_[curr];
                node_ids[temp].conns[curr]->send_flow(path_max_flow, temp);
                curr = temp;
            }
        }
    };
}

using namespace dinics_algorithm;

int main() {
    level_graph<int> flow_graph;
    int nodes[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            nodes[i][j] = i * 3 + j;
            flow_graph.add_node(i * 3 + j);
        }
    }
    flow_graph.add_connection(SOURCE, nodes[0][0], 5, 0);
    flow_graph.add_connection(SOURCE, nodes[1][0], 10, 0);
    flow_graph.add_connection(SOURCE, nodes[2][0], 15, 0);
    flow_graph.add_connection(nodes[0][0], nodes[1][0], 0, 15);
    flow_graph.add_connection(nodes[0][0], nodes[0][1], 10, 0);
    flow_graph.add_connection(nodes[1][0], nodes[1][1], 20, 0);
    flow_graph.add_connection(nodes[2][0], nodes[1][1], 0, 5);
    flow_graph.add_connection(nodes[2][0], nodes[2][1], 25, 0);
    flow_graph.add_connection(nodes[0][1], nodes[1][1], 25, 0);
    flow_graph.add_connection(nodes[0][1], nodes[1][2], 0, 15);
    flow_graph.add_connection(nodes[0][1], nodes[0][2], 10, 0);
    flow_graph.add_connection(nodes[1][1], nodes[1][2], 30, 0);
    flow_graph.add_connection(nodes[2][1], nodes[1][2], 20, 0);
    flow_graph.add_connection(nodes[2][1], nodes[2][2], 10, 0);
    flow_graph.add_connection(nodes[0][2], SINK, 5, 0);
    flow_graph.add_connection(nodes[1][2], SINK, 15, 0);
    flow_graph.add_connection(nodes[1][2], nodes[1][2], 15, 0);
    flow_graph.add_connection(nodes[2][2], SINK, 10, 0);
//    for (auto conn: flow_graph.node_ids[SOURCE].conns) {
//        cout << SOURCE << " " << conn.first << endl;
//    }
    cout << flow_graph.dinics_max_flow() << endl;
}