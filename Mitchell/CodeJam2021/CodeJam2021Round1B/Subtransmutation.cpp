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
#define repi(_a) for(ll i=0;i<_a;i++)
#define repj(_a) for(ll j = 0; j < _a; j++)
#define repk(_a) for(ll k = 0; k < _a; k++)
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
//bool test(vi u, int a, int b, vi v){
//    vi cur;
//    int val[u.length];
//    repi(u.length) val[i] = 0;
//    bool result = false;
//    repi(v.size()){
//        if(v[i] == 1)
//            result = true;
//    }
//    if(!result) return false;
//    repi(v.size()){
//        cur.clear();
//        repj(v.size()){
//            if(i==j){
//                int t1 = v[i] - a;
//                int t2 = v[i] - b;
//                if(t1 > 0){
//                    cur.pb(t1);
//                    val[t1]++;
//                }
//                if(t2 > 0){
//                    cur.pb(t2);
//                    val[t2]++;
//                }
//            } else {
//                cur.pb(v[i]);
//                val[v[i]]++;
//            }
//        }
//        bool result = true;
//        for(int k = val.length-1; k >= 0; k--){
//            if(val[k] < u[k]){
//                result = false;
//            }
//        }
//        if(result) return true;
//        if(test(u, a, b, cur)) return true;
//    }
//    return false;
//}
//bool test(vi u, int a, int b, vi v){
//    for(int i = u.size(); i > 0; i--){
//        if(u[i-1] != 0){
//            while(v.back() > i){
//                int t1 = v.back()-a;
//                int t2 = v.back()-b;
//                v.pop_back();
//                if(t1>0) v.pb(t1);
//                if(t2>0) v.pb(t2);
//                sort(v.begin(), v.end());
//            }
//            int count = 0;
//            while(v.back() == i){
//                v.pop_back();
//                count++;
//                if(count >= u[i-1]) break;
//            }
//            if(count < u[i-1]) return false;
//        }
//    }
//    return true;
//}


bool test(vi u, int a, int b, vi v){
    for(int i = v.size()-1; i >= 0; i--){
        int c; 
        if(i >= u.size()) {
            c = v[i];
        } else {
            c = v[i]-u[i];
        }
        if(c<0){
            return false;
        }
        v[i] -= c;
        if(i-a>=0) v[i-a] += c;
        if(i-b>=0) v[i-b] += c;
    }
    return true;
}

int myfunc(vi u, int a, int b, int s){
    bool result = false;
    int i;
    for(i = s+1; !result; i++){
        //cout<<"testing"<<i<<nn;
        vi v;
        repj(i) v.pb(0);
        v.pb(1);
        result = test(u, a, b, v);
        if(i > 420) return -1;
    }
    return i;
}

int main(){
    //fastinput();

    //---------SOLUTION----------//

    int T;
    cin>>T;
    repi(T){
        int a, b, n;
        cin>>n>>a>>b;
        vi u;
        int maxI = 0;
        repj(n){
            int t;
            cin>>t;
            u.pb(t);
            if(t!=0) maxI = j;
        }
        //cout<<maxI<<nn;
        cout<<"Case #"<<i+1<<": ";
        int val = myfunc(u, a, b, maxI);
        if(val == -1){
            cout<<"IMPOSSIBLE";
        } else {
            cout<<val;
        }
        cout<<nn;
    }
    return 0;
}

