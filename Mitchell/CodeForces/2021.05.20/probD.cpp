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
vi vals;
int n;

struct node{
    vi con;

    node(){
        con.clear();
    }
    node(int v){
        con.clear();
    }
};

V<node> nodes;
V<V<bool>> visited;

void rec(int b, int p, int c, vi cur){
    cur.pb(c);
    visited[b][c] = true;
    visited[c][b] = true;
    sort(cur.begin(), cur.end());
    for(int i = 0; i <= n; i++){
        if(i >= cur.size() || cur[i] != i){
            vals[i]++;
            break;
        }
    }

    for(int nc : nodes[c].con) {
        if(nc != p){
            if(!visited[b][nc]){
                rec(b, c, nc, cur);
            }
            if(!visited[c][nc]){
                vi ncur(1,c);
                rec(c, c, nc, ncur);
            }
        }
    }
}

int leaf(int p, int c){
    if(nodes[c].con.size() == 1)
        return c;
    if(nodes[c].con[0] != p)
        return leaf(c, nodes[c].con[0]); 
    return leaf(c, nodes[c].con[1]); 
}

int solve(){
    int t, n, f, l;
    cin>>t;
    while(t--){
        cin>>n;
        ::n = n;
        visited.clear();
        visited.resize(n, V<bool>(n));
        nodes.clear();
        nodes.resize(n);
        vals.clear();
        vals.resize(n+1);
        for(int i = 0; i < n-1; i++){
            cin>>f>>l;
            nodes[f].con.pb(l);
            nodes[l].con.pb(f);
        }
        int b = leaf(-1, 0);
        vi cur(1,b);
        rec(b, b, nodes[b].con[0], cur);
        for(int i : vals){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

