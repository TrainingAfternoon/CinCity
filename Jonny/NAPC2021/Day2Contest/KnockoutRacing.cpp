//
// Created by Jonny Keane on 8/10/21.
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

    int n, m;
    cin >> n >> m;
    int car_movements[n][4]; // store start, end, and the length
    // want to see modulus of twice the length
    // if in second half, take subtraction from the end
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        car_movements[i][0] = a;
        car_movements[i][1] = b;
        car_movements[i][2] = abs(b - a);
        car_movements[i][3] = a < b ? 1 : 0;
    }

    for (int i = 0; i < m; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        int res = 0;
        for (int j = 0; j < n; ++j) {
            if (car_movements[j][3] == 1 && (car_movements[j][0] > y || car_movements[j][1] < x))
                continue;
            if (car_movements[j][3] == 0 && (car_movements[j][1] > y || car_movements[j][0] < x)) continue;
            if (car_movements[j][3] == 1 && car_movements[j][0] >= x && car_movements[j][1] <= y) {
                ++res;
                continue;
            }
            if (car_movements[j][3] == 0 && car_movements[j][1] >= y && car_movements[j][0] <= x) {
                ++res;
                continue;
            }
            int dist_from_start = t % (car_movements[j][2]);
            if ((t / car_movements[j][2]) % 2 == 1) {
                dist_from_start = car_movements[j][2] - dist_from_start;
            }
            int loc = car_movements[j][0];
            if (car_movements[j][3] == 1) {
                loc += dist_from_start;
            } else {
                loc -= dist_from_start;
            }
            if (loc >= x && loc <= y) {
                ++res;
            }
        }
        cout << res << endl;
    }

    return 0;
}

