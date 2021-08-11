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

    map<char, char> trans;
    map<char, int> cycle_lens;
    for (char curr = 'A'; curr < 'A' + 26; ++curr) {
        string mapping;
        cin >> mapping;
        trans[curr] = mapping[0];
    }
    string _mapping;
    cin >> _mapping;
    trans['_'] = _mapping[0];
    for (char curr = 'A'; curr < 'A' + 26; ++curr) {
        char cycle_curr = trans[curr];
        int cycle_len = 1;
        while(cycle_curr != curr) {
            cycle_curr = trans[cycle_curr];
            ++cycle_len;
        }
        cycle_lens[curr] = cycle_len;
    }
    char _cycle_curr = trans['_'];
    int _cycle_len = 1;
    while(_cycle_curr != '_') {
        _cycle_curr = trans[_cycle_curr];
        ++_cycle_len;
    }
    cycle_lens['_'] = _cycle_len;
    int N;
    cin >> N;
    string msg;
    cin >> msg;
    for (char c: msg) {
        int c_cycle_len = cycle_lens[c];
        int shifts = N % c_cycle_len;
        char curr_c = c;
        for (int i = 0; i < shifts; ++i) {
            curr_c = trans[curr_c];
        }
        cout << curr_c;
    }
    cout << endl;

    return 0;
}