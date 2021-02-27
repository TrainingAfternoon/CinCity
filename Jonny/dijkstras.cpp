//
// Created by Jonny Keane on 2/26/21.
//

//
// FinalVersion.cpp
// SingleSourceShortestPath
//
// Created by Jonny Keane on 11/12/20.
// Copyright © 2020 Jonny Keane. All rights reserved.
//

#include <stdc++.h>
#include <tuple>

using namespace std;

class DijstrasStep {
public:
    DijstrasStep(int nodeID, int totalDist) : nodeID(nodeID), totalDist(totalDist) {};
    int nodeID;
    int totalDist;
    friend bool operator<(const DijstrasStep& a, const DijstrasStep& b);
};

bool operator<(const DijstrasStep& a, const DijstrasStep& b) {
    return a.totalDist > b.totalDist;
}

const int INF = 1000000007;

int main(int argc, const char* argv[]) {
    int GRAPH_LENGTH = -1;
    int edges = -1;
    int queries = -1;
    int initial = -1;
    while (true) {
        cin >> GRAPH_LENGTH;
        if (GRAPH_LENGTH == 0) break;
        cin >> edges >> queries >> initial;
        vector<pair<int, int>> graph[GRAPH_LENGTH];
        for (int i = 0; i < edges; i++) {
            int nodeA, nodeB, weight;
            cin >> nodeA >> nodeB >> weight;
            graph[nodeA].push_back(make_pair(nodeB, weight)); //only one add because it is directional
        }
        int tableOfPaths[GRAPH_LENGTH];
        for (int i = 0; i < GRAPH_LENGTH; i++) tableOfPaths[i] = INF;
        priority_queue<DijstrasStep> pq;
        pq.push(DijstrasStep(initial, 0));
        //MAIN LOOP
        while (!pq.empty()) {
            DijstrasStep shortest = pq.top();
            pq.pop();
            if (shortest.totalDist >= tableOfPaths[shortest.nodeID]) {
                continue;
            }
            tableOfPaths[shortest.nodeID] = shortest.totalDist;
            for (const auto& p: graph[shortest.nodeID]) {
                pq.push(DijstrasStep(p.first, shortest.totalDist + p.second));
            }
        }
    }
}

