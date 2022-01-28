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
int main(){
    fastinput();

    //---------SOLUTION----------//
    double b0, b1, b2, b3, t0, t1, t2, t3;
    vector<double> ans; 
    while(cin >> b0 >> b1 >> b2 >> b3 >> t0 >> t1 >> t2 >> t3) {
        auto h = [b0, b1, b2, b3, t0, t1, t2, t3](const double& x) {
            return (b0-t0) + (b1-t1)*x + (b2-t2)*x*x + (b3-t3)*x*x*x;
        };

        double a = 3*(b3-t3);
        double b = 2*(b2-t2);
        double c = (b1-t1);

        double h0 = 0;
        double h1 = 0;
        double inside = b*b - 4*a*c;
        if(inside >= 0) { //avoid imaginary roots
            h0 = (-b + sqrt(inside))/(2*a);
            if(h0 != h0 || h0 < 0 || h0 > 1)
                h0 = 0.0;
            h1 = (-b - sqrt(inside))/(2*a);
            if(h1 != h1 || h1 < 0 || h1 > 1)
                h1 = 0.0;
     
        }
        h0 = h(h0);
        h1 = h(h1);
        double h2 = h(0.0);
        double h3 = h(1.0);

        double _max = max(h0, max(h1, max(h2, h3)));
        double _min = min(h0, min(h1, min(h2, h3)));
        
        //cout << h0 << endl << h1 << endl << h2 << endl << h3 << endl;

        ans.pb(_max - _min);
    }

    cout << setprecision(10);
    for (auto answer : ans) {
        cout << answer << endl;
    }
    return 0;
}
