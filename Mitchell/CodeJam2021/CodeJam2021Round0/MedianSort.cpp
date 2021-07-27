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
vi v;
void bs(int t){
    int f=0, m, l=v.size()-1, r;
    while(f!=l){
        m = (l+f)/2;
        if(f==m){
            //now check against l. will be 1 apart. insert before, after, or
            //between;
            cout<<v[f]<<" "<<v[l]<<" "<<t<<endl;
            cin>>r;
            if(r==v[f]){
                v.insert(v.begin()+f,t);
            } else if (r==v[l]){
                v.insert(v.begin()+l+1,t);
            } else {
                v.insert(v.begin()+l,t);
            }
            break;
        } else {
            cout<<v[f]<<" "<<v[m]<<" "<<t<<endl;
            cin>>r;
            if(r==v[f]){
                v.insert(v.begin()+f,t);
                break;
            } else if (r==v[m]){
                if(m+1==l){
                    //only one more check
                    cout<<v[m]<<" "<<v[l]<<" "<<t<<endl;
                    cin>>r;
                    //can never be m as the median
                    if(r==v[l]){
                        v.insert(v.begin()+l+1,t);// insert at end
                    } else {
                        v.insert(v.begin()+m+1,t);//insert between
                    }
                    break;
                } else {
                    f = m+1;
                }
            } else { // means t is the median
                if(m-1==f){
                    v.insert(v.begin()+f+1,t);
                    break;
                } else {
                    l = m-1;
                }
            }
        }
    }
    //cout<<"\t";
    //for(int val:v){
        //cout<<val<<" ";
    //}
    //cout<<nn;
}
int main(){
    fastinput();

    //---------SOLUTION----------//

    int T, N, Q;
    cin>>T>>N>>Q;
    for(int z = 0; z<T; z++){
        //this is gonna be similar to a binary search. Kinda wahck tho, so
        v.clear();
        cout<<"1 2 3"<<endl;
        int m;
        cin>>m;
        if(m==1){
            v.pb(2);
            v.pb(1);
            v.pb(3);
        } else if(m==2){
            v.pb(1);
            v.pb(2);
            v.pb(3);
        } else {
            v.pb(1);
            v.pb(3);
            v.pb(2);
        }
        for(int i = 4; i <= N; i++){
            bs(i);
        }
        for(int val : v){
            cout<<val<<" ";
        }
        cout<<endl;
        int tmp;
        cin>>tmp;
        if(tmp != 1){
            cout<<"failed"<<nn;
            break;
        }
    }
    return 0;
}

