#include <bits/stdc++.h>
#include <string> 
#include <vector> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <algorithm> 
#include <functional> 
#include <iostream> 
#include <sstream> 
#include <cstdio> 

// var types
#define ll long long
#define ld long double
#define nn '\n'
#define pb push_back
#define mp make_pair

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>

// loops
#define repi(a) for(ll i=0;i<a;i++)
#define repj(a) for(ll j = 0; j < a; j++)
#define repk(a) for(ll k = 0; k < a; k++)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define in_map(m,e) (m.find(e) == m.end())
#define findchar(s,c) s.find(c)==string::npos?-1:s.find(c);

using namespace std;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// functs
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;} 
// trim from start (in place)
static inline void ltrim(std::string &s) {s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {return !std::isspace(ch);}));}
// trim from end (in place)
static inline void rtrim(std::string &s) {s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {return !std::isspace(ch);}).base(), s.end());}
// trim from both ends (in place)
static inline void trim(std::string &s) {ltrim(s);rtrim(s);}

void fastinput(){ios_base::sync_with_stdio(0); cin.tie(0);}

// -------------------MAIN CODE-------------------//
int main(){
    fastinput();

    //---------SOLUTION----------//

    int t, n, c, sum;
    cin>>t;
    repk(t){
        cin>>n>>c;
        if(n>c+1){
            cout<<"Case #"<<k+1<<": IMPOSSIBLE"<<endl;
            continue;
        }
        vi v;
        for(int i = 1; i < n+1; i++){
            v.pb(i);
        }
        sum = 0;
        bool flipped = false;
        vi front;
        vi back;
        repi(n-1){
            //reverse(v.begin()+i, v.end());
            //check if flipping the whole thing, plus the checks, will be less
            //than the current c
            //else, only flip part that we need
            if(c >= 2*v.size()-2){
                //we're flipping
                if(!flipped){
                    back.pb(v[0]);
                } else {
                    front.pb(v[0]);
                }
                flipped = !flipped;
                c-=v.size();
                v.erase(v.begin());
            } else {
                if(c<v.size()-1){//means we can't check, wrong
                    c=1; //fake val, sets so it'll display Impossible
                } if(c==v.size()-1){
                    c=0; // works, single checks, all the way through
                }else {
                    //only flip part
                    c-=v.size()-2; //due to single value checks
                    reverse(v.end()-c, v.end());
                    c=0;
                }
                break;
            }
            if(c==0) break;
        }
        if(c!=0){
            cout<<"Case #"<<k+1<<": IMPOSSIBLE"<<endl;
        } else {
            cout<<"Case #"<<k+1<<": ";
            for(int val: front) cout<<val<<" ";
            if(flipped){
                for(int i = v.size()-1; i>=0; i--) cout<<v[i]<<" ";
            } else {
                for(int i = 0; i<v.size(); i++) cout<<v[i]<<" ";
            }
            for(int i = back.size()-1; i>=0; i--) cout<<back[i]<<" ";
            cout<<endl;
        }
    }

    return 0;
}

