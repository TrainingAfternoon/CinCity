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

//This is GARBAGE because they're in a CIRCLE
void brute_force_solve(const string& begin, const string& end, string test) {
    for(int i = 0; i < end.length(); i++) {
        if(test.at(i) != end.at(i)) {
            if(i != end.length() - 1) {
                for(int j = i + 1; j < end.length(); j++) {
                    if(test.at(j) == end.at(i)) {
                        for(int k = i; k <= j; k++) {
                            test.at(k) = test.at(j);
                        }
                        break;
                    }
                } 
            } else {
                if(test.at(i-1) == end.at(i)) {
                    test.at(i) = test.at(i-1);
                }
            }
        }
    }
    if(test != end) {
       for(int i = end.length() - 1; i >= 0; i--) {
            //New addition------------------
            for(int k = i - 1; k >= 0; k--) {
                if(test.at(k) == end.at(i)) {
                    for(int s = k + 1; s <= i; s++) {
                        test.at(s) = test.at(k);
                    }
                    break;
                }
            }
       }
    }
    cout << test << endl;
    cout << ((test == end) ? "yes" : "no") << endl;
}

//This is GARBAGE because they're in a CIRCLE
void new_brute_force_solve(const string& end, string test) {
    string backup = test;
    for(int i = 0; i < end.length(); i++) {
        if(test.at(i) != end.at(i)) {
            if(i != end.length() - 1) {
                for(int j = i + 1; j < end.length(); j++) {
                    if(test.at(j) == end.at(i)) {
                        for(int k = i; k <= j; k++) {
                            test.at(k) = test.at(j);
                        }
                        break;
                    }
                } 
            } else {
                if(test.at(i-1) == end.at(i)) {
                    test.at(i) = test.at(i-1);
                }
            }
        }
    }
    
    if(test != end) {
        for(int i = end.length() - 1; i >= 0; i--) {
            if(backup.at(i) != end.at(i)) {
                if(i != 0) {
                    for(int j = i - 1; j >= 0; j--) {
                        if(backup.at(j) == end.at(i)) {
                            for(int k = i; k > j; k--) {
                                backup.at(k) = backup.at(j);
                            }
                            break;
                        }
                    }
                } else {
                    if(backup.at(i+1) == end.at(i)) {
                        backup.at(i) = backup.at(i+1);
                    }
                }
            }
        }
        cout << (backup == end ? "yes" : "no") << endl;
    } else {
        cout << "yes" << endl;
    }
}

void circular_brute_force_solve(const string& end, string test) {
    string backup = test;
    for(int i = 0; i < end.length(); i++) {
        if(test.at(i) != end.at(i)) {
            if(i != end.length() - 1) {
                for(int j = i + 1; j < end.length(); j++) {
                    if(test.at(j) == end.at(i)) {
                        for(int k = i; k <= j; k++) {
                            test.at(k) = test.at(j);
                        }
                        break;
                    }
                } 
            } else {
                if(test.at(i-1) == end.at(i)) {
                    test.at(i) = test.at(i-1);
                } else if(test.at(0)) {
                    test.at(i) = test.at(0);
                }
            }
        }
    }
    
    if(test != end) {
        for(int i = end.length() - 1; i >= 0; i--) {
            if(backup.at(i) != end.at(i)) {
                if(i != 0) {
                    for(int j = i - 1; j >= 0; j--) {
                        if(backup.at(j) == end.at(i)) {
                            for(int k = i; k > j; k--) {
                                backup.at(k) = backup.at(j);
                            }
                            break;
                        }
                    }
                } else {
                    if(backup.at(i+1) == end.at(i)) {
                        backup.at(i) = backup.at(i+1);
                    } else if(backup.at(end.length()-1) == end.at(i)) {
                        backup.at(i) = backup.at(end.length()-1);
                    }
                }
            }
        }
        cout << (backup == end ? "yes" : "no") << endl;
    } else {
        cout << "yes" << endl;
    }

}

bool ar = false;
bool ab = false;
string inverse(const string& in) {
    string out = in;
    for(int i = 0; i < out.length(); i++) {
        if(out.at(i) == 'B') {
            ar = true;
            out.at(i) = 'R';
        } else {
            ab = true;
            out.at(i) = 'B';
        }
    }
    return out;
}

bool edge_match(const string &a, const string& b) {
    return a.at(0) == b.at(0) && a.at(a.length()-1) == b.at(b.length()-1);
}

bool matching_sets(const string& b) {
    return (ar && b.find("R") != string::npos) && (ab && b.find("B")!=string::npos);
}

bool matching_cross_pairs(const string& a, const string& b) {
    int arb, abr;
    for(int i = 0; i < a.length()-1; i++) {
        if(a.at(i) == 'R' && a.at(i+1) == 'B') {
            arb++;
        } else if(a.at(i) == 'B' && a.at(i+1) == 'R') {
            abr++;
        }
    }
    int brb, bbr;
    for(int i = 0; i < b.length()-1; i++) {
        if(b.at(i) == 'R' && b.at(i+1) == 'B') {
            brb++;
        } else if(b.at(i) == 'B' && b.at(i+1) == 'R') {
            bbr++;
        }
    }
    return arb+abr >= brb+bbr;
}

void inverse_solve(const string& a, const string& b) {
    bool is_inverse = inverse(a) == b;
    cout << (is_inverse && edge_match(a,b) || !is_inverse && matching_sets(b) && matching_cross_pairs(a,b) ? "yes" : "no") << endl;
}

int main(){
    fastinput();

    //---------SOLUTION----------//
    int n;
    string beg, end;
    
    cin >> n;
    cin >> beg;
    cin >> end;
    //brute_force_solve(beg, end, beg);
    circular_brute_force_solve(end, beg);
    inverse_solve(beg, end);
    return 0;
}
