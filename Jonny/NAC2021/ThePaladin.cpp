//
// Created by Jonny Keane on 8/14/21.
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

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // need to construct k - 1 pieces
    int n, k;
    cin >> n >> k;
    unordered_map<string, int> costs;
    unordered_map<char, unordered_set<char>> conns;
    unordered_map<string, string> matchings;
    vector<string> segs;
    for (int i = 0; i < n; ++i) { /// taking in the possible segs
        string part;
        int cost;
        cin >> part >> cost;
        costs[part] = cost;
        if (part[0] == part[1]) {
            segs.emplace_back(part);
            costs[part] *= 2;
            continue;
        }
        string rev({part[1], part[0]});
        if (matchings.find(rev) == matchings.end()) {
            matchings[part] = "";
        } else {
            matchings[rev] = part;
        }
    }
    for (auto p: matchings) { /// filtering to valid pieces
        if (!p.second.empty()) {
            int sum = costs[p.first] + costs[p.second];
            costs[p.first] = sum;
            costs[p.second] = sum;
            segs.emplace_back(p.first);
            segs.emplace_back(p.second);
        }
    }
    int choices = k / 2;
    int dp[choices][26];
    for (int i = 0; i < choices; ++i) {
        for (int j= 0; j < 26; ++j) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < segs.size(); ++i) {
        string part = segs[i];
        if (conns.find(part[0]) == conns.end()) {
            conns[part[0]] = unordered_set<char>();
        }
        conns[part[0]].insert(part[1]);
    }
    if (k % 2 == 0) { /// init dp
        for (string s: segs) {
            if (s[0] == s[1]) {
                dp[0][s[1] - 'a'] = min(costs[s] / 2, dp[0][s[1] - 'a']);
            }
        }
    } else {
        for (string s: segs) {
            dp[0][s[1] - 'a'] = min(costs[s], dp[0][s[1] - 'a']);
        }
    }
    for (int i = 0; i < choices - 1; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (dp[i][j] == INT_MAX || conns.find((char)('a' + j)) == conns.end()) continue;
            for (char conn: conns[(char)('a' + j)]) {
                string part({(char)('a' + j), conn});
                dp[i + 1][conn - 'a'] = min(dp[i][j] + costs[part], dp[i + 1][conn - 'a']);
            }
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < 26; ++i) {
        res = min(res, dp[choices - 1][i]);
    }
    if (res == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }

    /// dp to string
//    for (int i = 0; i < choices; ++i) {
//        for (int j = 0; j < 26; ++j) {
//            if (dp[i][j] == INT_MAX) {
//                cout << "-1" << " ";
//            } else {
//                cout << dp[i][j] << " ";
//            }
//        }
//        cout << endl;
//    }

    return 0;
}