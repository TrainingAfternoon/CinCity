#include <bits/stdc++.h>
#include <regex>
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

void fastinput(){ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);}

bool is_prime(long num) {
    if(num == 1) {
        return true;
    }
    for(int i = 2; i < sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

bool check_leading(string str) {
    if(str.size() > 0) {
        if(str.at(0) == '0' && str.size() != 1) {
            return false;
        }
    }
    return true;
}

int resolve(V<string> strings) {
    //Break:
    //  more than 3 contiguous number candidates
    //  sum is less than 3 (can generalize to all)
    //  any of the num candidates > 10^9 (len > 9)
    //  any of the number candidates < 0
    //  sum candidates not prime
    
    if(strings.empty() || strings.size() > 3) {
        return 0;
    }
    
    long sum;
    long a;
    long b;

    //Bounds checking && leading_zero check
    for(int i = 0; i < strings.size(); i++) {
        if(strings.at(i).size() > 9 || check_leading(strings.at(i))) {
            return 0;
        }
    }
    
    //Handle string --> long
    sum = stol(strings.at(0));
    a = stol(strings.at(1));
    b = stol(strings.at(2));

     

    //Prime checking
    if(!is_prime(a) || !is_prime(b)) {
        return 0;
    }

    //Trivial checks
    return sum <= pow(10, 9) && sum > 3 && sum % 2 == 0 && a > 0 && b > 0 && (a + b) == sum;    
}

// -------------------MAIN CODE-------------------//
int main(){
    fastinput();

    //---------SOLUTION----------//
    string line;
    string aggregate;
    while(getline(cin, line)) {
        aggregate.append(line.append("\n"));
    } 
    
    //cout << "Out of read" << endl;
    //cout << "Aggregate: " << aggregate << endl;

    V<string> strings;
    //regex non_num("[^\\d]*"); //DOES NOT HANDLE NEG NUM
    //regex non_num("-(?!\\d)|[^\\d]*");//NEGATIVE case -- sregex_it does not lie
    regex non_num("-(?!\\d)|\\D\\S");
    regex num("-(?=\\d)[\\d]+|[\\d]+");
    //regex num("(?<=^|[\\d\\s\\n])(-(?=\\d){1}[\\d]+|[\\d]+)(\\n|\\s|$)(?![^\\d\\s\\n])"); //cpp does not like backreferences :(

    //check to see if input has any illegal characters:
    if(regex_search(aggregate, non_num)) {
        cout << "0" << endl;
        return 0;
    }

    //Sanitize input for desired nums
    sregex_iterator it(aggregate.begin(), aggregate.end(), num);
    sregex_iterator reg_end;
    
    //int iterations(0);
    //string tmp;
    string regex_aggregate;
    for(; it != reg_end; ++it) {
        //cout << it->str() << endl;
        //iterations++;
        strings.pb(it->str());
    }
    //cout << iterations << endl;
        
    cout << resolve(strings) << endl;
    return 0;
}
