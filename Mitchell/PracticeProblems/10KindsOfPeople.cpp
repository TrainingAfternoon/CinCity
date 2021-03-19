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

graph table;

void paint(int x, int y, int val, int p){
    if(x >= 0 && x < table.size() && y >= 0 && y < table[0].size() && table[x][y] == val){
        table[x][y] = p;
        paint(x-1, y, val, p);
        paint(x+1, y, val, p);
        paint(x, y-1, val, p);
        paint(x, y+1, val, p);
    }
}

void paint(){
    int curE = 2;
    int curO = 3;
    for(int i = 0; i < table.size(); i++){
        for(int j = 0; j < table[0].size(); j++){
            if(table[i][j] == 0){
                paint(i, j, 0, curE);
                curE += 2;
            } else if(table[i][j] == 1){
                paint(i, j, 1, curO);
                curO += 2;
            }
        }
    }
}

// -------------------MAIN CODE-------------------//
int main(){
    fastinput();

    //---------SOLUTION----------//
    int r, c;
    cin>>r>>c;
    string s;
    repi(r){
        cin>>s;
        vi cur;
        repj(c){
            cur.pb(s[j]-'0');
        }
        table.pb(cur);
    }
    paint();

    int n;
    cin>>n;
    repi(n){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;
        x2--;
        y1--;
        y2--;
        //cout<<"\t"<<table[x1][y1]<<" "<<table[x2][y2]<<nn;
        if(table[x1][y1] != table[x2][y2]){
            cout<<"neither"<<nn;
        } else if ((table[x1][y1]&1) == 0){
            cout<<"binary"<<nn;
        } else {
            cout<<"decimal"<<nn;
        }
    }
    return 0;
}

