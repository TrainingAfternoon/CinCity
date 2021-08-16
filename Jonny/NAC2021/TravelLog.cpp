//
// Created by Jonny Keane on 8/14/21.
//

#include <bits/stdc++.h>

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

//
// Created by Jonny Keane on 6/18/21.
//

/// Dijkstra's Algorithm classes
namespace DijkstrasAlg {
    /// Enumerates infinity
    enum {
        INF = 1000000007
    };

    /// A step forward in dijkstra's algorithm
    /// \tparam W The type of the weight (int/double)
    template<typename W>
    class DijkstrasStep {
    public:
        int nodeID;
        W totalDist;

        /// Initializes node ID and total distance
        /// \param nodeID Node ID
        /// \param totalDist Total distance
        DijkstrasStep(int nodeID, W totalDist) : nodeID(nodeID), totalDist(totalDist) {};

        /// Comparator of DijkstrasSteps for use in priority queue
        /// \param a A step
        /// \param b Another step
        /// \return If a is "lesser"
        /// \tparam The type of the weight (int/double)
        friend bool operator<(const DijkstrasStep<W> &a, const DijkstrasStep<W> &b) {
            return a.totalDist > b.totalDist;
        }
    };

    /// Class to hold Dijsktra's Algorithm
    /// \tparam W The type of the weight (int/double)
    template<typename W>
    class Dijkstras {
    public:
        vector<pair<int, W>> * graph;
        W* shortestPathTable;
        int* parents;
        long* pathCounts;
        int numNodes;

        /// Initializes the Dijkstras object
        /// \param graph The assembled graph
        Dijkstras(vector<pair<int, W>> * graph, int numNodes) : graph(graph), numNodes(numNodes) {
                shortestPathTable = new W[numNodes];
                parents = new int[numNodes];
                pathCounts = new long[numNodes];
        }

        /// Runs Dijkstra's Algorithm on the graph
        /// \param start The node to start at
        void dijkstras(int start) {
            clearShortestPaths();
            priority_queue<DijkstrasStep<W>> pq;
            pq.push(DijkstrasStep<W>(start, 0));
            //MAIN LOOP
            while (!pq.empty()) {
                DijkstrasStep<W> shortest = pq.top();
                pq.pop();
                if (shortest.totalDist > shortestPathTable[shortest.nodeID]) {
                    continue;
                }
                if (shortest.nodeID == numNodes - 1 && shortestPathTable[shortest.nodeID] == shortest.totalDist) {
                    ++pathCounts[shortest.nodeID];
                } else {
                    shortestPathTable[shortest.nodeID] = shortest.totalDist;
                    pathCounts[shortest.nodeID] = 1;
                    for (const auto &p: graph[shortest.nodeID]) {
                        parents[p.first] = shortest.nodeID;
                        pq.push(DijkstrasStep<W>(p.first, shortest.totalDist + p.second));
                    }
                }
            }
        }

    private:
        /// Clears the shortestPathTable for another run of algorithm from another starting point
        void clearShortestPaths() {
            for (int i = 0; i < numNodes; ++i) {
                shortestPathTable[i] = INF;
            }
        }
    };
}

using namespace DijkstrasAlg;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // longs for shortest steps
    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> conns[n]; // {node, weight}
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        conns[u].emplace_back(make_pair(v, w));
    }

    Dijkstras<long> dj(reinterpret_cast<vector<pair<int, long>> *>(conns), n);
    dj.dijkstras(0);
    for (int i = 0; i < d; ++i) {

    }

    return 0;
}