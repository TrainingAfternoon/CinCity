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

    int t, n, sum;
    cin>>t;
    repk(t){
        cin>>n;
        vi v;
        repi(n){
            int temp;
            cin>>temp;
            v.pb(temp);
        }
        sum = 0;
        repi(n-1){
            int j = find(v.begin()+i, v.end(), *min_element(v.begin()+i, v.end())) - v.begin();
            reverse(v.begin()+i, v.begin()+j+1);
            //cout<<"\t"<<i<<" "<<j<<nn;
            //for(int f = i; f < i+(j-i)/2; f++){
                //int l = j-f;
                //v[f] ^= v[l];
                //v[l] ^= v[f];
                //v[f] ^= v[l];
            //}
            sum+=j-i+1; 
        }
        cout<<"Case #"<<k+1<<": "<<sum<<endl;
    }
    return 0;
}

