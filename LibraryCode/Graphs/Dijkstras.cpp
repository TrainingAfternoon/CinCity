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
            friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b);
    };

    /// Operator for comparing the Dij
    /// \param a A step
    /// \param b Another step
    /// \return If a is "lesser"
    bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        return a.totalDist > b.totalDist;
    }

    /// Class to hold Dijsktra's Algorithm
    /// \tparam W The type of the weight (int/double)
    template<typename W>
    class Dijkstras {
        public:
            vector<pair<int, W>> graph;
            W* shortestPathTable;

            /// Initializes the Dijkstras object
            /// \param graph The assembled graph
            Dijkstras(vector<pair<int, W>> graph) : graph(graph) {
                shortestPathTable = new W[graph.size()];
                for (int i = 0; i < graph.size(); ++i) {
                    shortestPathTable[i] = INF;
                }
            }

            /// Runs Dijkstra's Algorithm on the graph
            /// \param start The node to start at
            void dijkstras(int start) {
                priority_queue<DijkstrasStep<W>> pq;
                pq.push(DijkstrasStep<W>(start, 0));
                //MAIN LOOP
                while (!pq.empty()) {
                    DijkstrasStep<W> shortest = pq.top();
                    pq.pop();
                    if (shortest.totalDist >= shortestPathTable[shortest.nodeID]) {
                        continue;
                    }
                    shortestPathTable[shortest.nodeID] = shortest.totalDist;
                    for (const auto& p: graph[shortest.nodeID]) {
                        pq.push(DijkstrasStep<W>(p.first, shortest.totalDist + p.second));
                    }
                }
            }
    };
}