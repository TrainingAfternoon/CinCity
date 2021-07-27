#include <bits/stdc++.h>
#include <chrono>

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
using namespace std::chrono;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// -------------------STRUCTS---------------------//


// -------------------FUNCTIONS-------------------//


// -------------------SOLUTION--------------------//
int solve(){
    vi count;
    vi bs;
    char cur;
    int index = 0;
    int test;
    cin>>test;
    auto start = high_resolution_clock::now();
    while(test--){
        cin>>cur;
    //while(cin>>cur){
        count.pb(0);
        if(cur == 'A'){
            for(int i : bs) count[index-i]++;
        } else {
            bs.pb(index);
        }
        index++;
    }
    for(int i = 1; i < count.size(); i++) cout<<count[i]<<nn;
    auto stop = high_resolution_clock::now();
    cout<<"that took:"<<nn;
    cout<<(duration_cast<microseconds>(stop-start)).count()<<nn;

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

