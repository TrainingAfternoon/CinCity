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

int recurse(V<V<bool>>& ints, vi& rows, int cur, int k){
    if(rows.size() > k){
        return 0;
    }
    if(cur == ints[0].size()){
        return 1;
    }
    bool r = false;
    for(int i = 0; i < ints.size(); i++){
        if(ints[i][cur]){
            r = true;
            int temp;
            if(find(rows.begin(), rows.end(), i) == rows.end()){
                rows.pb(i);
                temp = recurse(ints, rows, cur+1, k);
                rows.pop_back();
            } else {
                temp = recurse(ints, rows, cur+1, k);
            }
            if(temp == 0) continue;
            else return temp;
        }
    }
    if(!r)
        return -1;
    return 0;
}

bool r2(V<V<bool>>& ints, V<bool> rows, int row, int k){
    if(k == 0){
        for( bool b : rows ) {
            if(!b) return false;
        }
        return true;
    }
    if(row >= ints.size()) return false;
    if(r2(ints, rows, row+1, k)) return true;
    bool done = false;
    for(int i = 0; i < ints[row].size(); i++){
        rows[i] = rows[i] || ints[row][i];
        done = done && rows[i];
    }
    if(done) return true;
    return r2(ints, rows, row+1, k-1);
}
// -------------------SOLUTION--------------------//
int solve(){
    V<V<bool>> bools;
    int m, n, k, t;
    cin>>m>>n>>k;
    for(int i = 0; i < m; i++){
        V<bool> cur(n);
        for(int j = 0; j < n; j++){
            cin>>t;
            cur[j] = (t == 0);
        }
        bools.pb(cur);
    }
//    vi rows;
//    int i = recurse(bools, rows, 0, k);
//    if(i == 1) cout<<"yes";
//    else cout<<"no";
    V<bool> ns(n);
    for(int i = 0; i < n; i++){
        ns[i] = false;
    }
    if(r2(bools, ns, 0, k)) cout<<"yes";
    else cout<<"no";
    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

