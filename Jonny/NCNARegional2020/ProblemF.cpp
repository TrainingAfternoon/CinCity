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

vector<vector<pair<ll, ll>>> graph_;

pair<ll, ll> DFS(ll curr, ll m, ll prev) {
    pair<ll, ll> res = make_pair(curr, m);
    for (auto adj: ::graph_[curr]) {
        if (adj.first != prev) {
            pair<ll, ll> poss = DFS(adj.first, m + adj.second, curr);
            if (poss.second > res.second) {
                res = poss;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int GRAPH_LENGTH, k;
    cin >> GRAPH_LENGTH >> k;
    int edges = GRAPH_LENGTH - 1;

    ll sum = 0;
    for (int i = 0; i < GRAPH_LENGTH; ++i) {
        vector<pair<ll, ll>> temp;
        ::graph_.pb(temp);
    }
    for (int i = 0; i < edges; i++) {
        int nodeA, nodeB, weight;
        cin >> nodeA >> nodeB >> weight;
        nodeA--;
        nodeB--;
        sum += weight;
        ::graph_[nodeA].pb(make_pair(nodeB, weight));
        ::graph_[nodeB].pb(make_pair(nodeA, weight));
    }
    if (k >= 2) {
        cout << sum;
    } else {
        ll firstRun = DFS(0, 0, 0).first;
        cout << DFS(firstRun, 0, firstRun).second;
    }
    return 0;
}
