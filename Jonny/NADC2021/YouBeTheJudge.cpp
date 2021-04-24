//
// Created by Jonny Keane on 4/22/21.
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

    int nums[3];
    string curr;
    int i = 0;
    while (cin >> curr) {
        if (i == 3) {
            cout << 0 << nl;
            return 0;
        }
        try {
            cin >> curr;
            if (curr == "DONE") break;
            nums[i++] = stoi(curr);
        } catch (exception exception) {
            cout << 0 << nl;
            return 0;
        }
    }
    cout << nums[0] << ' ' << nums[1] << ' ' << nums[2] << nl;
    return 0;
}