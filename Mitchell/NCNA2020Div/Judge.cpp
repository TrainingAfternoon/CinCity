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
#define endl '\n'
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
bool p(int n){
    if(n==2) return true;
    if((n&1) == 0) return false;
    for(int i = 3; i < ((int) sqrt(n)) + 1; i+=2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    //fastinput();

    //---------SOLUTION----------//

    int n = 0;
    int nums[3];
    repi(3){
        nums[i] = -1;
    }
    string t = "";
    V<string> strings;
    while(cin>>t){
        strings.pb(t);
    }
    if(strings.size() != 3){
        cout<<0<<endl;
        return 0;
    }
    for(string t : strings){
        if(t.size() == 0 || t == "" || t[0] == '0' || t[0] == '-' || t[0] == '+' ){
                cout<<0<<endl;
                return 0;
        }
        repj(t.size()){
            if((t[j] < '0') || (t[j] > '9')){
                cout<<0<<endl;
                return 0;
            }
        }
        try{
            int temp = stoi(t);
            nums[n++] = temp;
        } catch(...){
            cout<<0<<endl;
            return 0;
        }
    }
    if(nums[0] > 3 && nums[0] <= 1000000000 && nums[1] <= 1000000000 && nums[2] <= 1000000000){
        if(nums[0] == (nums[1] + nums[2])){
            if(nums[0] > 3){
            //if(nums[0] > 0 && nums[1] > 0 && nums[2] > 0){
                if(((nums[0])%2) == 0){
                    if(p(nums[1]) && p(nums[2])){
                        cout<<1<<endl;
                        return 0;
                    }
                }
            }
            //}
        }
    }
    cout<<0<<endl;
    return 0;
}
