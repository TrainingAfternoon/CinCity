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
const double PI = 3.1415926585323;
#define FIND(a, e) find(a.begin(), a.end(), e)


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // code here
    int N;
    double R, S, W, F, L1, L2;
    cin >> N >> R >> S >> W >> F >> L1 >> L2;
    double D;
    while (cin >> D) {
        printf("%.3f ", D);

        for(int i = 0; i < N; ++i) {
            double x = F;
            double y;
            double d = 0.0;
            if (D < F + S / 2.0) {
                printf("%.3f %.3f ", x - D, y);
                break;
            }
            d += F + S / 2.0;
            while (d < D) {
                if (d + PI*R > 200.0) {

                }
            }
        }
    }
    return 0;
}
