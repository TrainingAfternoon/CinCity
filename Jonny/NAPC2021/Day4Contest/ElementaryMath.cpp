//
// Created by Jonny Keane on 8/12/21.
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

    int n;
    cin >> n;

    vector<pair<set<long>, vector<char>>> dp[n];

    map<char, int> ops;
    ops['+'] = 0;
    ops['-'] = 1;
    ops['+'] = 2;
    long probs[n][2];
    long sols[n][3];
    for (int i = 0; i < n; ++i) {
        cin >> probs[i][0] >> probs[i][1];
        sols[i][0] = probs[i][0] + probs[i][1];
        sols[i][1] = probs[i][0] - probs[i][1];
        sols[i][2] = probs[i][0] * probs[i][1];
    }
    dp[0].emplace_back(make_pair(set<long>({sols[0][0]}), vector<char>({'+'})));
    dp[0].emplace_back(make_pair(set<long>({sols[0][1]}), vector<char>({'-'})));
    dp[0].emplace_back(make_pair(set<long>({sols[0][2]}), vector<char>({'*'})));

    for (int i = 0; i < n - 1; ++i) {
        for (auto p: dp[i]) {
            if (p.first.count(sols[i + 1][0]) == 0) {
                set<long> copy_s(p.first);
                copy_s.insert(sols[i + 1][0]);
                vector<char> copy_v(p.second);
                copy_v.emplace_back('+');
                dp[i + 1].emplace_back(make_pair(copy_s, copy_v));
            }
            if (p.first.count(sols[i + 1][1]) == 0) {
                set<long> copy_s(p.first);
                copy_s.insert(sols[i + 1][1]);
                vector<char> copy_v(p.second);
                copy_v.emplace_back('-');
                dp[i + 1].emplace_back(make_pair(copy_s, copy_v));
            }
            if (p.first.count(sols[i + 1][2]) == 0) {
                set<long> copy_s(p.first);
                copy_s.insert(sols[i + 1][2]);
                vector<char> copy_v(p.second);
                copy_v.emplace_back('*');
                dp[i + 1].emplace_back(make_pair(copy_s, copy_v));
            }
        }
    }
    if (dp[n - 1].empty()) {
        cout << "impossible" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << probs[i][0] << " " << dp[n - 1][0].second[i] << " " << probs[i][1] << " = " << sols[i][ops[dp[n - 1][0].second[i]]] << endl;
        }
    }

    return 0;
}