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

int recurse(V<V<bool>>& bools, V<vi>& rowsContaining,V<bool>& row, int n, int k){
    if(k == 0) return -1;
    if(n >= bools[0].size()){
        return 0;
    }
    for(int r : rowsContaining[n]){
        V<bool> cur(row.size());
        bool done = true;
        for(int i = 0; i < row.size(); i++){
            cur[i] = row[i] || bools[r][i];
            if(!cur[i]) done = false;
        }
        if(done) return 1;
        for(int i = 0; i < cur.size(); i++){
            if(!cur[i]){
                int t = recurse(bools, rowsContaining, cur, i, k-1);
                if(t != 0) return t;
            }
        }
    }
    return -1;
}
// -------------------SOLUTION--------------------//
int solve(){
    V<V<bool>> bools;
    int m, n, k, t;
    cin>>m>>n>>k;
    V<vi> rowsContaining(n);
    for(int i = 0; i < n; i++){
        vi r;
        rowsContaining[i] = r;
    }
    for(int i = 0; i < m; i++){
        V<bool> cur(n);
        for(int j = 0; j < n; j++){
            cin>>t;
            cur[j] = (t == 0);
            if(cur[j]) rowsContaining[j].pb(i);
        }
        bools.pb(cur);
    }
    V<bool> cur(n,false);
    int result = recurse(bools, rowsContaining, cur, 0, k);
    if(result == 1) cout<<"yes";
    else cout<<"no";
    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

