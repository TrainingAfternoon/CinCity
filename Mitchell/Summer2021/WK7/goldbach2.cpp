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
void sieve(V<int>& p, int max){
    V<bool> s(max+1, true);
    s[0] = false;
    s[1] = false;
    for(int c = 2; c < max + 1; c++){
        if(s[c]){
            p.pb(c);
            for(int i = c*c; i < max + 1; i += c) s[i] = false;
        }
    }
}


// -------------------SOLUTION--------------------//
int solve(){
    vi p;
    sieve(p, 32000);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        V<string> s;
        int bottom = 0, top = p.size() - 1;
        while(bottom <= top){
            int sum = p[bottom] + p[top];
            if(sum == n){
                s.pb(to_string(p[bottom]) + "+" + to_string(p[top]));
                bottom++;
                top--;
            } else if (sum > n){
                top--;
            } else {
                bottom++;
            }
        }
        cout<<n<<" has "<<s.size()<<" representation(s)"<<nn;
        for(string sol : s) cout<<sol<<nn;
        cout<<nn;
    }


    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

