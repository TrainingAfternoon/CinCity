//
// Created by Jonny Keane on 8/12/21.
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

bool all_consec(bitset<51> b, int n) {
    for (int i = 1; i <= n; ++i) {
        if (!b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string joke;
    cin >> joke;

    int n;
    if( joke.size() > 10){
        n = 9 + (joke.size()-9)/2;
    } else {
        n = joke.size();
    }

    vector<pair<string, bitset<51>>> dp[joke.size()];
    dp[0] = vector<pair<string, bitset<51>>>(1);
    for (int i = 0; i < joke.size(); ++i) {
        string one_dig = joke.substr(i, 1);
        int one_dig_i = stoi(one_dig);
        if (one_dig_i > 0) {
            for (auto config: dp[i]) {
                if (config.second[one_dig_i]) continue;
                string copy_s(config.first);
                bitset<51> copy_b(config.second);
                copy_s += one_dig + " ";
                copy_b[one_dig_i] = true;
                if (all_consec(copy_b, n)) {
                    cout << copy_s << endl;
                    return 0;
                } else if (i + 1 <joke.size()) {
                    dp[i + 1].emplace_back(make_pair(copy_s, copy_b));
                }
            }
        }
        if (i < joke.size() - 1) {
            string two_dig = joke.substr(i, 2);
            if (two_dig[0] == '0') continue;
            int two_dig_i = stoi(two_dig);
            if (two_dig_i <= 50) {
                for (auto config: dp[i]) {
                    if (config.second[two_dig_i]) continue;
                    string copy_s(config.first);
                    bitset<51> copy_b(config.second);
                    copy_s += two_dig + " ";
                    copy_b[two_dig_i] = true;
                    if (all_consec(copy_b, n)) {
                        cout << copy_s << endl;
                        return 0;
                    } else if (i + 2 < joke.size()) {
                        dp[i + 2].emplace_back(make_pair(copy_s, copy_b));
                    }
                }
            }
        }
//        cout << i << endl;
//        for (auto p: dp[i]) {
//            cout << p.first << endl;
//        }
    }
//    cout<<" done ";
    return 0;
}