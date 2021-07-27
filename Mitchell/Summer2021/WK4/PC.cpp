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
    cin>>n>>m;
    vi task(n);
    vi quiet(m);
    for(int i = 0; i < n; i++) cin>>task[i];
    for(int i = 0; i < m; i++) cin>>quiet[i];

    sort(task.begin(), task.end(), greater<int>());
    sort(quiet.begin(), quiet.end(), greater<int>());

//    for(int i = 0; i < n; i++) cout<<task[i]<<" ";
//    cout<<nn;
//    for(int i = 0; i < m; i++) cout<<quiet[i]<<" ";
//    cout<<nn;

    int i = 0, j = 0;
    while(i < n && j < m){
        if(task[i] <= quiet[j]){
            i++;
            j++;
        } else {
            i++;
        }
    }
    cout<<j;
    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

