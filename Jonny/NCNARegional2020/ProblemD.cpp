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
    string s;
    while(cin >> s) {
        int count = 0;
        set<char> chars;
        for(char c: s) {
            chars.insert(c);
        }
        if (chars.size() == 1 && s.length() != 1) {
            cout << 1 << nl;
            continue;
        }
        if (chars.size() == s.length()) {
            cout << 0 << nl;
            continue;
        }
        set<string> working;
        for(int i = 0; i < s.length() - chars.size() + 1; ++i) { // for every substring
            string sub = s.substr(i);
            set<char> subChars;
            for (int j = 0; j < sub.length(); ++j) { // every character in sub
//                if (subChars.count(sub[j])) break;
                subChars.insert(sub[j]);
                if (subChars.size() == chars.size()) {
                    if (sub[j - 1] != sub[j] && sub[j] != sub[0] && sub[0] != sub[1]) {
                        string res = sub.substr(0, j+1);
                        while (res.substr(1).find(res[0]) != string::npos) res = res.substr(1);
                        working.insert(res);
                        count++;
                        break;
                    }
                }
            }

        }
        cout << working.size() << nl;
    }

    return 0;
}