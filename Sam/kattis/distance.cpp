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
#define umap unordered_map

// loops
#define WHILE(n) while(n--)
#define repi(a) for(ll i=0;i<a;i++)
#define repj(a) for(ll j = 0; j < a; j++)
#define repk(a) for(ll k = 0; k < a; k++)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define in_map(m,e) (m.find(e) == m.end())
#define findchar(s,c) s.find(c)==string::npos?-1:s.find(c);

// Methods
#define lex_com(a,b) lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())

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

void fastinput(){ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);}

// -------------------MAIN CODE-------------------//

ll dist(vector<ll> axis) {
    sort(axis.begin(), axis.end());
    
    ll res = 0;
    ll sum = 0;
    for(ll i = 0; i < axis.size(); i++) {
        res += (axis[i]*i) - sum;
        sum += axis[i];
    }
    return res;
}
int main(){
    fastinput();

    //---------SOLUTION----------//
    //O(nlogn)
    //For the sets X, Y:
    //res = sum of distances up to xi-1
    //xi is the next greatest point
    //To get the distance of each point from xi, we do res + sum(xi - xk) where xk is defined x where x < xi
    //
    //res = res + (x2 - x1) + (x3 - x2) + ... + (xi - xi-1)
    //Because our array is sorted, 
    //res = res + i(xi) - (x1 + x2 + ... + xi-1)
    //res = res + i(xi) - Si-1, where Si-1 is the sum of all points up to index i - 1
    
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    cout << dist(x) + dist(y) << endl;
    return 0;
}

