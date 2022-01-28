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
    int x, y, n;
    cin>>x>>y>>n;
    for(int i = 1; i <= n; i++){
        bool f = i%x==0, b = i%y==0;
        if(f && b){
            cout<<"FizzBuzz";
        } else if(f){
            cout<<"Fizz";
        } else if(b){
            cout<<"Buzz";
        } else {
            cout<<i;
        }
        cout<<nn;
    }


    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

