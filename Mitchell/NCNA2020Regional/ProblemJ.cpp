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
#define WHILE(n) while(n--)
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
vd lengths;
int N, d, s, t;
bool visited[11];
void solve(int index, double length, int e){
        //cout<<"found new length!"<<nn;
    if(index == ::N) {
        ::lengths.pb(2*(length + (e)*(::t)));
        return;
    }
    if(::visited[index]) return;
    ::visited[index] = true;

    e++;

    //adjacent eyelets
    solve(index+1, length + ::d, e);
    solve(index-1, length + ::d, e);
    //any on other side
    for(int i = 2; i <= ::N; i++){
        if(::visited[i]) continue;
        solve(i, length + sqrt(pow(::s,2) + pow(::d*(abs(i-index)),2)), e);
    }
    ::visited[index] = false;
    return;
}
int main(){
    fastinput();

    //---------SOLUTION----------//
    double fmin, fmax;
    cin>>::N>>::d>>::s>>::t>>fmin>>fmax;

    repi(11){
        ::visited[i] = false;
    }
    ::visited[0] = ::visited[10] = true;
    solve(1,.5*(::s),1);

    double l;
    while(cin>>l){
        int sum = 0;
        for(double length : ::lengths){
            //cout<<"Current length: "<<length<<nn;
            double cur = (l-length)/2.0;
            if(fmin <= cur && fmax >= cur){
                sum++;
            }
        }
        cout<<sum<<nn;
    }
    return 0;
}

