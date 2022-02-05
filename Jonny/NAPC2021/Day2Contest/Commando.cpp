//
// Created by Jonny Keane on 8/11/21.
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

int A, B, C;

long long g(long long x) {
    long long res = A * x * x;
    res += B * x;
    res += C;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin >> A >> B >> C;
    int X[n];
    int S[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> X[i];
        sum += X[i];
        S[i] = sum;
    }

    long long pref[n];
    pref[0] = g(S[0]);
    for (int i = 1; i < n; ++i) {
        long long max_ = g(S[i]);
        long long max_choice = i;
        for (int j = 0; j < i; ++j) {
//            if (pref[j] + g(S[i] - S[j]) > max_) {
//                max_choice = j;
//                cout << "Choice changed to" << j << endl;
//            }
            max_ = max(pref[j] + g(S[i] - S[j]), max_);
        }
//        cout << max_choice << endl;
        pref[i] = max_;
    }
    cout << pref[n - 1] << endl;

    return 0;
}