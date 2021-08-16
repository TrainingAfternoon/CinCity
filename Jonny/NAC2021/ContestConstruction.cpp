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

    // code here
    int n, k;
    cin >> n >> k;
    long long vals[n];
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }
    sort(vals, vals + n);
    map<pair<int, int>, long long> dp[k];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pair<int, int> p = make_pair(i, j);
            if (dp[1].find(p) == dp[1].end()) {
                dp[1][p] = 0;
            }
            ++dp[1][p];
        }
    }
    for (int i = 1; i < k - 1; ++i) {
        for (auto p: dp[i]) {
            for (int j = p.first.second + 1; j < n; ++j) {
                if (vals[j] <= vals[p.first.second] + vals[p.first.first]) {
//                    cout << vals[p.first.first] << " " << vals[p.first.second] << " " << vals[j] << endl;
                    pair<int, int> new_p = make_pair(p.first.second, j);
                    if (dp[i + 1].find(new_p) == dp[i + 1].end()) {
                        dp[i + 1][new_p] = 0;
                    }
                    dp[i + 1][new_p] += p.second;
                }
            }
        }
    }

    long long res = 0;
    for (auto p: dp[k - 1]) {
        res += p.second;
    }
    cout << res << endl;
    return 0;
}