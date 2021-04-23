//
// Created by team on 4/18/21.
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

// use M_PI for PI

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // code here
    int d, r, t;
    cin >> d >> r >> t;
    int rita = 4;
    int theo = 4 - d;
    int ritaCandles = 0;
    int theoCandles = 0;
    int sum = r + t;
    while (ritaCandles + theoCandles != sum) {
        ritaCandles += rita++;
        if (theo >= 3) {
            theoCandles += theo++;
        } else {
            ++theo;
        }
    }
    cout << r - ritaCandles;

    return 0;
}

