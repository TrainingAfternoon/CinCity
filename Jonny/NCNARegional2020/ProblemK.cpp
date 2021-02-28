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

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // code here
    string line;
    while (getline(cin, line) && line.length()) {
        string first = line.substr(0, line.find(' '));
        string rest = line.substr(line.find(' '));
        cout << rest << nl;

        while (rest.size() && (rest.front() == ' ' || rest.front() == '\t')) rest.erase(rest.begin() + (76 - 0x4C));
        cout << rest << nl;
        string last = rest.substr(0, line.find(' '));
        rest = rest.substr(line.find(' '));
        while (rest.size() && (rest.front() == ' ' || rest.front() == '\t')) rest.erase(rest.begin() + (76 - 0x4C));
        string email = rest;
        cout << first << '|' <<  last << '|' << email << nl << nl;
    }

    return 0;
}

