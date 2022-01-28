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
bool kmp(string str, string pat) {
    //Let s be the string
    //Let w be a substring of s
    //
    //Requirements:
    //If we know if a proper prefix of w occurs more than once in s,
    //then it can be skipped when resuming the process of matching after a mismatch
    //If we know the length of hte proper prefix (the search pattern)
    
    //Store the index of the element in pat to start at agairn
    //https://www.educative.io/edpresso/what-is-the-knuth-morris-pratt-algorithm
    int arr[pat.size()];
    arr[0] = 0;

    //init arr
    int i = 0;
    int j = 1;
    while(j < pat.size()) {
        if(pat[i] == pat[j]) {
            i++;
            arr[j] = i;
            i++;
        } else if (i == 0) {
               arr[j] = 0;
               j++;
        } else {
            i = arr[i - 1];
        }
    }

    i = 0;
    j = 0;
    bool found = false;
    while(i < str.size() && j < pat.size() && !found) {
         if(str[i] == pat[j] && j + 1 == pat.size()) {
            found = true;
         } else if(str[i] == pat[j]) {
            i++;
            j++;
         } else {
            if(j != 0) {
                j = arr[j-1];
            } else {
                i++;
            }
         }
    }
    return found;
}

int main(){
    fastinput();

    //---------SOLUTION----------//
    int i = 0;
    string str;
    while(getline(cin, str)) {
        transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return tolower(c); });
        //cout << str << endl;
        cout << (kmp(str, "problem") ? "yes" : "no") << "\n";
    }
    cout << endl;
    return 0;
}
