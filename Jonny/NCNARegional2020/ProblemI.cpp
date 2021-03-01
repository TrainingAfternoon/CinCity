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
            double y = -(R + (double)i * W);
            double runningRadius = i == 0 ? R + L1 : R + (double)i * W + L2;
            double innerTrackRadius = R + (double)i * W;
            double lap = 2.0 * S + (2 * M_PI * runningRadius);
            double remaining = fmod(D, lap);
            if (remaining < F + S/2.0) {
                x -= remaining;
                printf("%.4f %.4f ", x, y);
                continue;
            } else {
                remaining -= F + S/2.0;
            }
            if (remaining < M_PI * runningRadius) {
                x = -1.0 * (S/2 + innerTrackRadius * cos(remaining / runningRadius - M_PI/2));
                y = innerTrackRadius * sin(remaining / runningRadius - M_PI/2);
                printf("%.4f %.4f ", x, y);
                continue;
            } else {
                remaining -= M_PI * runningRadius;
            }
            if (remaining < S) {
                x = -S/2.0 + remaining;
                y = -y;
                printf("%.4f %.4f ", x, y);
                continue;
            } else {
                remaining -= S;
            }
            if (remaining < M_PI * runningRadius) {
                x = S/2 + innerTrackRadius * cos(-(remaining / runningRadius - M_PI/2));
                y = innerTrackRadius * sin(-(remaining / runningRadius - M_PI/2));
                printf("%.4f %.4f ", x, y);
                continue;
            } else {
                remaining -= M_PI * runningRadius;
            }
            x = S/2 - remaining;
            printf("%.4f %.4f ", x, y);
        }
        cout << nl;
    }
    return 0;
}
