//
// Created by Jonny Keane on 8/13/21.
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

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
string padding = "!";

string base_64_decode(string encoded) {

}

string base_64_encode(string decoded) {
    for (int i = 0; i < decoded.size() % 4; ++i) {
        decoded += padding;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    // 3 bytes -> 4 characters

    return 0;
}