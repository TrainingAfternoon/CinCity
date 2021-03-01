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

pair<int, ll> DFS(int curr, vector<DijstrasStep> *graph_) {
    ll sum = 0;
    while (true) {
        int next = 0;
        for (int i = 0; i < graph_[curr].size(); ++i) { // finds the maximum
            if (graph_[curr][i].totalDist > graph_[curr][next].totalDist) {
                next = i;
            }
        }
        int nextNode = graph_[curr][next].nodeID;
        if (graph_[curr][next].totalDist == 0) break;
        sum += graph_[curr][next].totalDist;
        for (int i = 0; i < graph_[nextNode].size(); ++i) { // finds the other direction to remove
            if (graph_[nextNode][i].nodeID == curr) {
                graph_[nextNode][i].totalDist = 0;
            }
        }
        graph_[curr][next].totalDist = 0;
        curr = nextNode;
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
    vector<DijstrasStep> graph_copy[GRAPH_LENGTH];
    ll sum = 0;
    for (int i = 0; i < edges; i++) {
        int nodeA, nodeB, weight;
        cin >> nodeA >> nodeB >> weight;
        nodeA--;
        nodeB--;
        sum += weight;
        graph_[nodeA].pb(DijstrasStep(nodeB, weight));
        graph_[nodeB].pb(DijstrasStep(nodeA, weight));
        graph_copy[nodeA].pb(DijstrasStep(nodeB, weight));
        graph_copy[nodeB].pb(DijstrasStep(nodeA, weight));
    }
    if (k >= 2) {
        cout << sum;
    } else {
        cout << DFS(DFS(0, graph_).first, graph_copy).second;
    }
    return 0;
}
