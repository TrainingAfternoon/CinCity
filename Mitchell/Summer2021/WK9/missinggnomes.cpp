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
#define vii V<vi>
#define vll V<ll> 
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>

// funcs 
#define inRange(x,y,l,w) (x >= 0 && x < l && y >= 0 && y < w)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define in_map(m,e) (m.find(e) == m.end())
#define findchar(s,c) s.find(c)==string::npos?-1:s.find(c);

using namespace std;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// -------------------STRUCTS---------------------//


// -------------------FUNCTIONS-------------------//


// -------------------SOLUTION--------------------//
int solve(){
    int n, m;
    cin>>n>>m;
    int order[m];
    bool missing[n+1];
    for(int i = 0; i < n+1; i++) missing[i] = true;
    for(int i = 0; i < m; i++){
        cin>>order[i];
        missing[order[i]] = false;
    }
    int mi = 0;
    while(mi < n+1 && !missing[++mi]);
    while(mi < order[0]){
        cout<<mi<<nn;
        while(mi < n+1 && !missing[++mi]);
    }
    cout<<order[0]<<nn;
    for(int i = 1; i < m; i++){
        while(mi > order[i-1] && mi < order[i]){
            cout<<mi<<nn;
            while(mi < n+1 && !missing[++mi]);
        }
        cout<<order[i]<<nn;
    }
    while(mi < n+1){
        if(missing[mi]) cout<<mi<<nn;
        mi++;
    }


    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

