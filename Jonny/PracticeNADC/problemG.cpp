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

//    map<string, string> schoolsToUni;
    int n;
    cin >> n;
//    string order[n];
    set<string> placed;
    int place = 0;

    for (int i = 0; i < n; ++i) {
        if (place == 12) {
            break;
        }
        string school, uni;
        cin >> uni >> school;
        if (placed.count(uni) == 0) {
            cout << uni << " " << school << nl;
            placed.insert(uni);
            ++place;
        }
    }


    return 0;
}