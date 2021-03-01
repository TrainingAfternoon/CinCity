//
// Created by Jonny Keane on 2/27/21.
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
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define FIND(a, e) find(a.begin(), a.end(), e)

#define nl '\n'

using namespace std;

class DijstrasStep {
public:
    DijstrasStep(int nodeID, int totalDist) : nodeID(nodeID), totalDist(totalDist) {};
    int nodeID;
    int totalDist;
    friend bool operator<(const DijstrasStep& a, const DijstrasStep& b);
};

bool operator<(const DijstrasStep& a, const DijstrasStep& b) {
    return a.totalDist < b.totalDist;
}

pair<int, int> DFS(int curr, vector<DijstrasStep> *graph_) {
    vi visited;
//    visited.pb(curr);
    int sum = 0;
    while (true) {
        int count = 0;
        priority_queue<DijstrasStep> pq;
        for (DijstrasStep d: graph_[curr]) {
            if (FIND(visited, d.nodeID) == visited.end()) {
                pq.push(d);
//                cout << d.nodeID << ", " << d.totalDist << nl;
                count++;
            }
        }
        if (count == 0) break;
        curr = pq.top().nodeID;
        visited.pb(curr);
        sum += pq.top().totalDist;
//        cout << "\tS: " << sum << nl;
    }
    return make_pair(curr, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int GRAPH_LENGTH, k;
    cin >> GRAPH_LENGTH >> k;
    int edges = GRAPH_LENGTH - 1;

    vector<DijstrasStep> graph_[GRAPH_LENGTH];
    int sum;
    for (int i = 0; i < edges; i++) {
        int nodeA, nodeB, weight;
        cin >> nodeA >> nodeB >> weight;
        nodeA--;
        nodeB--;
        sum += weight;
        graph_[nodeA].pb(DijstrasStep(nodeB, weight));
        graph_[nodeB].pb(DijstrasStep(nodeA, weight));
    }
    if (k >= 2) {
        cout << sum;
    } else {
        cout << DFS(DFS(0, graph_).first, graph_).second;
    }

    return 0;
}
