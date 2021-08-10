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
    /*
        P: Given a set of n days, choose the best day i to start, so that
        i and i + 1 are minimized / have the lowest upper bound possible

        A: start at odd number (1) and iterate through all odd numbers in n (1 3 5 7 etc)
        between the -1 and +1 offsets, keep track of a minimum m
        iterate through all items and update m when both -1 and +1 are below. Thankfully,
        we don't care about average heat so it is fine to decrease as long as m decreases, even
        if the average doesn't decrease. We prefer the smallest d, so m should only be replaced
        when curr_m is lower, not equal to

        C: frame three iteration, champion algorithm
    */

    int n;
    cin >> n;

    vector<int> days;
    repi(n) {
        int d;
        cin >> d;
        days.pb(d);
    }

    /*int day = 1;
    int m = max(days[0], days[2]);
    for(int i = 1; i < days.size() - 1; i++) {
        if(days[i-1] < m && days[i+1] < m) {
            day = i;
            m = max(days[i-1], days[i+1]);
        }
    }*/

    int day = 0;
    int m = max(days[0], days[2]);
    for(int i = 1; i < days.size() - 2; i++) {
        if(days[i] < m && days[i+2] < m) {
            day = i;
            m = max(days[i], days[i+2]);
        }
    }

    cout << day + 1 << " " << m << endl;
    return 0;
}
