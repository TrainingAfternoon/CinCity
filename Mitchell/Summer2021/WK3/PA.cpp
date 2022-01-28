#include <bits/stdc++.h>

// var types
#define ll long long
#define ld long double
#define nn '\n'
#define pb push_back
#define mp make_pair

// collection shorthand
#define V vector
#define vi V<int>
#define vll V<ll> #define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>

// loops
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define in_map(m,e) (m.find(e) == m.end())
#define findchar(s,c) s.find(c)==string::npos?-1:s.find(c);

using namespace std;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// -------------------SOLUTION--------------------//
int solve(){

    int n, m;
    string a, b;
    cin>>n;
    V<pair<int, string>> cups;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        try{
            m = stoi(a);
            cups.pb(mp(m, b));
        }catch(...){
            m = stoi(b);
            cups.pb(mp(m*2, a));
        }
    }
    sort(cups.begin(), cups.end());
    for(pair<int, string> cup : cups){
        cout<<cup.second<<nn;
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

