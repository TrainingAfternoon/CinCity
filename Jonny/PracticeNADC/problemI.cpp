//
// Created by team on 4/18/21.
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

// use M_PI for PI

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

//const int INF = 1000000007;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    // code here
//    int n, m;
//    cin >> n >> m;
//    int data[n][m];
//    set<pair<int, int>> visited;
//    visited.insert(make_pair(0,0));
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cin >> data[i][j];
//        }
//    }
//
//    return 0;
//}

