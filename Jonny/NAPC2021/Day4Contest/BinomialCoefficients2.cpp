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

    pair<int, string> results[1000000000000001];
    for (int i = 0; i < 1000000000000001; ++i) {
        results[i].first = 0;
    }

    long long pascal_vals[2][1000000000000001];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 1000000000000001; ++j) {
            pascal_vals[i][j] = 0;
        }
    }
    pascal_vals[0][0] = 1;
    int curr_layer = 0;
    int next_layer = 1;

    for (long i = 1; i < 1000000000000001; ++i) {
        pascal_vals[next_layer][0] = 1;
        for (long j = 0; j < i - 1; ++j) {
            if (pascal_vals[curr_layer][j] == 0 || pascal_vals[curr_layer][j + 1] == 0) {
                pascal_vals[next_layer][j + 1] = 0;
            } else {
                pascal_vals[next_layer][j + 1] = pascal_vals[curr_layer][j] + pascal_vals[curr_layer][j + 1];
            }
            if (pascal_vals[next_layer][j + 1] > 1000000000000001) {
                pascal_vals[next_layer][j + 1] = 0;
            }
            if (pascal_vals[next_layer][j + 1] < 1000000000000001) {
                if (results[pascal_vals[next_layer][j + 1]].first < 100) {
                    results[pascal_vals[next_layer][j + 1]].second += "(" + to_string(i) + "," + to_string(j + 1) + ") ";;
                    results[pascal_vals[next_layer][j + 1]].first++;
                }
            }
        }
        pascal_vals[next_layer][i] = 1;
        swap(curr_layer, next_layer);
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        cout << results[q].first << '\n' << results[q].second << endl;
    }

    return 0;
}