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
void addPath(vi paths[], int u, int v){
    paths[u].pb(v);
    paths[v].pb(u);
}
int solve(){
    int n,m,s,t;
    cin>>n>>m>>s>>t;

    vi paths[n];
    for(int i = 0; i < n; i++){
        vi cur;
        paths[i] = cur;
    }
    int u, v;
    while(m--){
        cin>>u>>v;
        paths[u].pb(v);
        paths[v].pb(u);
    }
//    for(int i = 0; i < n; i++){
//        cout<<i<<": ";
//        for(int c : paths[i]) cout<<c<<" ";
//        cout<<nn;
//    }

    vi got(n,0);
    vi give(n,0);
    give[s] = 1;
    while(t--){
        for(int i = 0; i < n; i++){
            //cout<<i<<": "<<give[i]<<nn;
            if(give[i]){
                for(int con : paths[i]){
                    got[con] += give[i];
                }
            }
        }
        for(int i = 0; i < n; i++){
            give[i] = got[i];
            got[i] = 0;
        }
    }
    __int128 sum = 0;
    for(int i = 0; i < n; i++) {
        sum += give[i];
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

