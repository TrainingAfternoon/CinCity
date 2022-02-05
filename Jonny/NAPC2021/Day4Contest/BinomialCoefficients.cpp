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

vector<long> pascal_vals[2];

void solutions(long q) {
    pascal_vals[0].clear();
    pascal_vals[1].clear();
    int curr_layer = 0;
    int next_layer = 1;
    pascal_vals[curr_layer].emplace_back(1);
//    cout << 1 << endl;
    pascal_vals[next_layer].emplace_back(0);
    string result;
    int count = 0;
    for (long i = 1; i < q + 1; ++i) {
        pascal_vals[next_layer][0] = 1;
//        cout << 1 << " ";
        for (long j = 0; j < i - 1; ++j) {
            if (pascal_vals[curr_layer][j] == 0 || pascal_vals[curr_layer][j + 1] == 0) {
                pascal_vals[next_layer][j + 1] = 0;
            } else {
//                cout << pascal_vals[curr_layer][j] << "+" << pascal_vals[curr_layer][j + 1] << "=" << to_string(pascal_vals[curr_layer][j] + pascal_vals[curr_layer][j + 1]) << endl;
                pascal_vals[next_layer][j + 1] = pascal_vals[curr_layer][j] + pascal_vals[curr_layer][j + 1];
            }
            if (pascal_vals[next_layer][j + 1] > q + 1) {
                pascal_vals[next_layer][j + 1] = 0;
            }
//            cout << pascal_vals[next_layer][j + 1] << " ";
            if (pascal_vals[next_layer][j + 1] == q) {
                if (count < 100) {
                    result += "(" + to_string(i) + "," + to_string(j + 1) + ") ";;
                    count++;
                }
            }
        }
        pascal_vals[next_layer].emplace_back(1);
        pascal_vals[curr_layer].emplace_back(0);
//        cout << 1 << endl;
        swap(curr_layer, next_layer);
    }
    cout << count << "\n" << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (long i = 0; i < n; ++i) {
        long q;
        cin >> q;
        solutions(q);
    }

    return 0;
}