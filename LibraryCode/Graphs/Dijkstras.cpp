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
        vector<pair<int, W>> graph*;
        W* shortestPathTable;
        int numNodes;

        /// Initializes the Dijkstras object
        /// \param graph The assembled graph
        Dijkstras(vector<pair<int, W>> graph*, int numNodes) : graph(graph), numNodes(numNodes) {
            shortestPathTable = new W[numNodes];
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
                if (shortest.totalDist >= shortestPathTable[shortest.nodeID]) {
                    continue;
                }
                shortestPathTable[shortest.nodeID] = shortest.totalDist;
                for (const auto& p: graph[shortest.nodeID]) {
                    pq.push(DijkstrasStep<W>(p.first, shortest.totalDist + p.second));
                }
            }
        }

    private:
        /// Clears the shortestPathTable for another run of algorithm from another starting point
        void clearShortestPaths() {
            for (int i = 0; i < graph.size(); ++i) {
                shortestPathTable[i] = INF;
            }
        }
    };
}