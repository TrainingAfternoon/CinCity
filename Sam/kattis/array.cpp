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
void print(V<string> seq) {
    for(int i = 0; i < seq.size() - 1; i++) {
        cout << seq[i] << " ";
    }
    cout << seq[seq.size()-1] << endl;
}

bool all_shared_digits_zero_for_b(string& a, string& b) {
    bool all_zero = true;
    for(int i = b.size() - a.size(); i < b.size() && all_zero; i++) {
        all_zero = b[i] == '0';
    }
    return all_zero;
}

int main(){
    fastinput();

    //---------SOLUTION----------//
    //Array of Discord
    int n;
    string a, b;

    cin >> n;
    V<string> seq(n);
    repi(n) {
        string s;
        cin >> seq[i];
    }
    
    int i = 0;
    do {
        a = seq[i++];
        b = seq[i];

        //do the thing
        if(a.size() == b.size()) {
            char ac, bc;
            for(int j = 0; j < a.size(); j++) {
                ac = a.at(j);
                bc = b.at(j);
                // 10 19 -- > 20 19 | 1 9 --> 1 0 
                if(ac != '0' || bc != '9') {
                    if (/*ac == '0'*/bc != '9') { //if bc < 9 increase a
                        seq[i-1][j] = bc + 1;
                        print(seq);
                        return 0;
                    } else { //if a > 0 decrease b
                        if(ac - 1 != '0') {
                            seq[i][j] = ac - 1;
                            print(seq);
                            return 0;
                        } else if((seq[i].size() != 1 && j != 0) || (j == 0 && seq[i].size() == 1)) {
                            seq[i][j] = ac - 1;
                            print(seq);
                            return 0;
                        }
                    } 
                }

           }
        }
    } while(i+1 < seq.size());
    cout << "impossible" << endl;
    return 0;
}
