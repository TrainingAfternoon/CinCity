//
// Created by Jonny Keane on 8/12/21.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)


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
        SINK = -2,
        SOURCE_MATCH = 0,
        SINK_MATCH = 1
    };

    /// A node in a flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class Node {
    public:
        /// The connections and where they lead (mapped for O(logn) indexing
        map<int, Connection<W>*> conns;
        short node_state = -3;
        Node(short node_state = 0) : node_state(node_state) {}
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

        vector<pair<int, int>> max_matching() {
            vector<pair<int, int>> result;
            for (auto node_id : nodes) {
                if (node_id.second.node_state == SOURCE_MATCH) {
                    for (auto conn: node_id.second.conns) {
                        if (nodes[conn.first].node_state == SINK_MATCH && conn.second->fwCap_(conn.first) > 0) {
                            result.emplace_back(make_pair(node_id.first, conn.first));
                        }
                    }
                }
            }
            return result;
        }

    private:
        map<int, int> parents;
        /// Sends flow down the path found by the bfs
        /// \param pathMaxFlow The path flow found
        void sendFlow(W pathMaxFlow) {
            int step = 0;
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

        /// contents for if dfs is needed
        set<int> dfs_visited;

        /// Searches for sink starting from source (depth search)
        /// \return The flow for a path to sink (-1 if fails)
        int dfs() {
            dfs_visited.clear();
            dfs_visited.insert(SOURCE);
            return dfs(SOURCE, INT_MAX);
        }

        /// Recursive portion of dfs
        /// \return The flow for a path to sink (-1 if fails)
        int dfs(int curr, int min_) {
            if (curr == SINK) return min_;
            for (auto nextConn: nodes[curr].conns) {
                int to = nextConn.second->to_(curr);
                W fwCap = nextConn.second->fwCap_(curr);
                if (dfs_visited.count(to) == 0 && fwCap > 0) {
                    dfs_visited.insert(to);
                    parents[to] = curr;
                    int search = dfs(to, min(min_, fwCap));
                    if (search != -1) {
                        return search;
                    }
                }
            }
            return -1;
        }
    };
}

using namespace MaxFlow;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    FlowGraph<int> flow_graph;
    unordered_map<int, string> node_ids;
    unordered_map<string, int> string_ids;
    unordered_set<int> sols;
    unordered_set<string> probs;
    int curr_node_id = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        /// add
        int add_sol = a + b;
        string add_prob = to_string(a) + " + " + to_string(b);
        int add_prob_node_id;
        int add_sol_node_id;
        if (sols.count(add_sol) == 0) {
            sols.insert(add_sol);
            add_sol_node_id = curr_node_id++;
            node_ids[add_sol_node_id] = to_string(add_sol);
            flow_graph.nodes[add_sol_node_id] = Node<int>(SINK_MATCH);
            flow_graph.addConnection(add_sol_node_id, SINK, 1, 0);
        } else {
            add_sol_node_id = string_ids[to_string(add_sol)];
        }
        if (probs.count(add_prob) == 0) {
            probs.insert(add_prob);
            add_prob_node_id = curr_node_id++;
            node_ids[add_prob_node_id] = add_prob;
            flow_graph.nodes[add_prob_node_id] = Node<int>(SOURCE_MATCH);
            flow_graph.addConnection(SOURCE, add_prob_node_id, 1, 0);

        } else {
            add_prob_node_id = string_ids[add_prob];
        }
        flow_graph.addConnection(add_prob_node_id, add_sol_node_id, 1, 0);
        /// sub
        int sub_sol = a - b;
        string sub_prob = to_string(a) + " - " + to_string(b);
        int sub_prob_node_id;
        int sub_sol_node_id;
        if (sols.count(sub_sol) == 0) {
            sols.insert(sub_sol);
            sub_sol_node_id = curr_node_id++;
            node_ids[sub_sol_node_id] = to_string(sub_sol);
            flow_graph.nodes[sub_sol_node_id] = Node<int>(SINK_MATCH);
            flow_graph.addConnection(sub_sol_node_id, SINK, 1, 0);
        } else {
            sub_sol_node_id = string_ids[to_string(sub_sol)];
        }
        if (probs.count(sub_prob) == 0) {
            probs.insert(sub_prob);
            sub_prob_node_id = curr_node_id++;
            node_ids[sub_prob_node_id] = sub_prob;
            flow_graph.nodes[sub_prob_node_id] = Node<int>(SOURCE_MATCH);
            flow_graph.addConnection(SOURCE, sub_prob_node_id, 1, 0);
        } else {
            sub_prob_node_id = string_ids[sub_prob];
        }
        flow_graph.addConnection(sub_prob_node_id, sub_sol_node_id, 1, 0);
        /// mult
        int mult_sol = a * b;
        string mult_prob = to_string(a) + " - " + to_string(b);
        int mult_prob_node_id;
        int mult_sol_node_id;
        if (sols.count(mult_sol) == 0) {
            sols.insert(mult_sol);
            mult_sol_node_id = curr_node_id++;
            node_ids[mult_sol_node_id] = to_string(mult_sol);
            flow_graph.nodes[mult_sol_node_id] = Node<int>(SINK_MATCH);
            flow_graph.addConnection(mult_sol_node_id, SINK, 1, 0);
        } else {
            mult_sol_node_id = string_ids[to_string(mult_sol)];
        }
        if (probs.count(mult_prob) == 0) {
            probs.insert(mult_prob);
            mult_prob_node_id = curr_node_id++;
            node_ids[mult_prob_node_id] = mult_prob;
            flow_graph.nodes[mult_prob_node_id] = Node<int>(SOURCE_MATCH);
            flow_graph.addConnection(SOURCE, mult_prob_node_id, 1, 0);
        } else {
            mult_prob_node_id = string_ids[mult_prob];
        }
        flow_graph.addConnection(mult_prob_node_id, mult_sol_node_id, 1, 0);
    }
    int max_flow = flow_graph.fordFulkerson();
    auto res = flow_graph.max_matching();
    if (max_flow < n) {
        cout << "impossible" << endl;
    } else {
        for (int i = 0; i < max_flow; ++i) {
            cout << res[i].first << "->" << res[i].second << endl;
            cout << node_ids[res[i].first] << " = " << node_ids[res[i].second] << endl;
        }
    }

    return 0;
}