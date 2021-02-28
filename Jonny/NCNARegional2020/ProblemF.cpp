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
    return a.totalDist > b.totalDist;
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
        graph_[nodeA].pb(DijstrasStep(nodeB, weight)); //only one add because it is directional
        graph_[nodeB].pb(DijstrasStep(nodeA, weight));
    }
    if (k >= 2) {
        cout << sum;
    } else {
        vi visited;
        visited.pb(0);
        int curr = 0;
        while (true) {
            sort(graph_[curr].begin(), graph_[curr].end());
            int j;
//            while(find(visited.begin(), visited.end(), graph_[j])) {
//                if ()
//            }
//            visited.pb(d.nodeID);
//            curr = d.nodeID;
        }
        cout << curr;
    }

    // code here

    return 0;
}
