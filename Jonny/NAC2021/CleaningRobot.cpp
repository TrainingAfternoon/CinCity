//
// Created by Jonny Keane on 8/16/21.
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

    int n, m, k;
    cin >> n >> m >> k;
    int grid[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m;++j) {
            grid[i][j] = 1;
        }
    }
    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        grid[r - 1][c - 1] = 0;
    }
    int max_ = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (grid[i][j] == 0) continue;
            grid[i][j] = min(min(grid[i - 1][j], grid[i][j - 1]), grid[i - 1][j - 1]) + 1;
            max_ = max(max_, grid[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}