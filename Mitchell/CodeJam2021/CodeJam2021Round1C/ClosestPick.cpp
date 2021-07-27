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

int main(){
    //fastinput();

    //---------SOLUTION----------//

    cout << fixed;
    cout << setprecision(8);
    int T;
    cin>>T;
    for(int i = 1; i <= T; i++){
        int N, P;
        cin>>N>>P;
        V<int> data;
        for(int j = 0; j < N; j++){
            int t;
            cin>>t;
            data.pb(t);
        }
        sort(data.begin(), data.end());

//        for(int i : data){
//            cout<<"\t"<<i<<" ";
//        }
        cout<<nn;
        int count1=0, count2=0;
        int countR = 0;

        int count = data[0]-1;
        if(count2 <= count) count2 = count;
        if(count1 <= count){
            count2=count1;
            count1=count;
            //cout<<"New num1: " <<num1<<nn;
        }
        for(int j = 1; j < N; j++){
            if(data[j-1] == data[j]){
                continue;
            }
            int test = data[j]-1;
            count = (test-data[j-1]+1)/2;
//            for(int c = test; c > data[j-1]; c--){
//                if(test-c < c-data[j-1]){
//                    count++;
//                } else {
//                    break;
//                }
//            }
            if(count2 <= count) count2 = count;
            if(count1 <= count){
                count2=count1;
                count1=count;
                //cout<<"New num1: " <<num1<<nn;
            }
            count = data[j]-data[j-1]-1;
            if(countR < count) countR=count;
        }
        count = P-data[N-1];
        if(count2 <= count) count2 = count;
        if(count1 <= count){
            count2=count1;
            count1=count;
            //cout<<"New num1: " <<num1<<nn;
        }
        double sum;
        if(count1+count2 > countR){
            sum = 1.0*(count1+count2);
        } else {
            sum = 1.0*countR;
        }
        //cout<<"SUM: "<<sum<<nn;
        cout<<"Case #"<<i<<": "<<(sum/P)<<nn;
    }
    return 0;
}

