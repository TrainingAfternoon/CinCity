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
// https://open.kattis.com/contests/z9dpdd/problems/missingnumber
int main(){
    fastinput();

    //---------SOLUTION----------//
    const int MAX = 128;
    int n;
    string word;
    cin >> n >> word;

    /* Cool bit hack, but kinda inefficient when we can do...
    //Technically the max is 100 bits, but 128 bits is nicer :)
    bitset<MAX> bits;
    bitset<MAX> standard;
    standard = (~standard) >> MAX - n;
    for(int i = 0; i < word.length(); i++) {
        int key = word[i] - 0x30;
        bits.set(key);
    }

    //~(0b111 & 0b101) = 0b010
    unsigned long long bit = (~(standard & bits)).to_ullong();*/
    /*int culprit = 0;
    int offset = 1;
    for(int i = 0; i < word.length() && culprit == 0; i += offset) {
        int curr = 0;
        if(offset == 1) {
            curr = word[i] - 0x30;
        } else if (offset == 2) {
            curr = (word[i-1]-0x30)*10 + word[i]-0x30;
        } else { //offset == 3, 100
            curr = (word[i-2]-0x30)*100 + (word[i-1]-0x30)*10 + word[i]-0x30;
        }
        //TODO: this only works when n < 10
        if(offset == 1 && curr != i + 1) {
                //cout << curr << endl;
                //cout << i << endl;
                culprit = i+1;
        } else if(offset == 2 && curr != i/2 + 5) {
            culprit = curr - 1;
            //cout << culprit << endl;
        }
        cout << curr << "," << i << "," << (i - curr%10) << endl;

        if(i >= 8) offset = 2;
        if(i >= 188) offset = 3;
    }

    //Special case, missing number is the last number
    if(culprit == 0) {
        culprit = n;
    }
    cout << culprit << endl;*/

    int gotcha = 0;
    int expected = 1;
    int offset = 1;
    for(int i = 0; i < word.length(); i += offset) {
        int curr = 0;
        if(offset == 1) {
            curr = word[i] - 0x30;
        } else if (offset == 2) {
            curr = (word[i-1]-0x30)*10 + word[i]-0x30;
        } else {
            curr = (word[i-2]-0x30)*100 + (word[i-1]-0x30)*10 + word[i]-0x30;
        }

        if(curr != expected) {
            gotcha = expected;
            break;
        }

        expected++;
        if(expected > 9) offset = 2;
        if(expected > 99) offset = 3;
    }

    //Special case
    if(gotcha == 0) gotcha = n;
    cout << gotcha << endl;

    return 0;
}
