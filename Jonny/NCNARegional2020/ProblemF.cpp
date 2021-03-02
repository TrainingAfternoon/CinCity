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
#define EXISTS(a, e) find(a.begin(), a.end(), e) != a.end()

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

pair<int, ll> DFS(int curr, vector<pair<int, int>> *graph_) {
    ll sum = 0;
    vector<int> visited;
    stack<DijstrasStep> pq; // prev
    pq.push(DijstrasStep(curr, 0));
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (EXISTS(visited, top.nodeID)) {
            continue;
        }
        if (top.totalDist >= sum) {
            sum = top.totalDist;
            curr = top.nodeID;
        }
        visited.pb(top.nodeID);
        for (auto connection: graph_[top.nodeID]) {
            pq.push(DijstrasStep(connection.first, top.totalDist + connection.second));
        }
    }
    return make_pair(curr, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int GRAPH_LENGTH, k;
    cin >> GRAPH_LENGTH >> k;
    int edges = GRAPH_LENGTH - 1;

    vector<pair<int, int>> graph_[GRAPH_LENGTH];
    vector<pair<int, int>> graph_copy[GRAPH_LENGTH];
    ll sum = 0;
    for (int i = 0; i < edges; i++) {
        int nodeA, nodeB, weight;
        cin >> nodeA >> nodeB >> weight;
        nodeA--;
        nodeB--;
        sum += weight;
        graph_[nodeA].pb(make_pair(nodeB, weight));
        graph_[nodeB].pb(make_pair(nodeA, weight));
        graph_copy[nodeA].pb(make_pair(nodeB, weight));
        graph_copy[nodeB].pb(make_pair(nodeA, weight));
    }
    if (k >= 2) {
        cout << sum;
    } else {
        cout << DFS(DFS(0, graph_).first, graph_copy).second;
    }
    return 0;
}
