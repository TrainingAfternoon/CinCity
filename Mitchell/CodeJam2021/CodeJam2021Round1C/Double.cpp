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

int v1(){
    //fastinput();

    //---------SOLUTION----------//

    int T = 0; 
    cin>>T;
    for(int i = 1; i <= T; i++){
        string start;
        string end;
        cin>>start>>end;
        int op = 0;
        string n = end;
        int dist = 0;
        for(int i = 0; i < n.size(); i++){
            if(i != 0 && end[i] != end[i-1]) dist++;
            if(n[i] == '0') n[i] = '1';
            else n[i] = '0';
        }
        char last = '2';
        int d = 0;
        for(int j = start.size()-end.size(); j < start.size(); j++){
            if(last != start[j]){
                last = start[j];
                d++;
            }
        }
        while(true){
            // check for distinct here;
            if(dist > d){
                op = -1;
                break;
            } else if(start.size() < end.size()) {
                if(start[start.size()-end.size()] != start[start.size()-end.size()+1]){
                    d--;
                }
                if(start[start.size()-1] == '0'){
                    start = start + "0";
                } else {
                    start = start + "1";
                }
                op++;
            }if(start.substr(start.size()-end.size()) == end){
                char last = '2';
                for(int j = start.size()-end.size()-1; j >= 0; j--){
                    if(last != start[j]){
                        op++;
                        last = start[j];
                    }
                }
                break;
            } else if(start.substr(start.size()-end.size()) == n){
                char last = '2';
                for(int j = start.size()-end.size()-1; j > 0; j--){
                    if(last != start[j]){
                        op++;
                        last = start[j];
                    }
                }
                op++;
                break;
            } else {
                if(start[start.size()-end.size()] != start[start.size()-end.size()+1]){
                    d--;
                }
                if(start[start.size()-1] == '0'){
                    start = start + "0";
                } else {
                    start = start + "1";
                }
                op++;
            }
        }
        
        if(op == -1){
            cout<<"Case #" <<i<<": IMPOSSIBLE"<<nn;
        } else {
            cout<<"Case #" <<i<<": "<<op<<nn;
        }
    }
    return 0;
}

string e;
int ed;
set<string> se;

string n(string s){
    string _n = s;
    for(int i = 0; i < _n.size(); i++){
        if(_n[i] == '0') _n[i] = '1';
        else _n[i] = '0';
    }
    return _n;
}

int match(string s, int dist, int op, int shift){
    if(shift > e.size()+1 || se.count(s) >= 1){
        return -1;
    }
    if(s == e){
        return op;
    }
    se.insert(s);

    // try not

    op++;
    int r = 0;
    string no = n(s);
    //cout<<" Performing Not on "<<s<<": "<<no<<nn;
    int i = no.find("1");
    if(i != string::npos){
        //cout<<"\tNow checking "<<no.substr(i)<<nn;
        r = match(no.substr(i), dist-1, op, shift);
    } else {
        r = match("0", 1, op, shift);
    }

    // try x2

    if(s[s.size()-1] != '0') dist++;
    int t = -1;
    if(s != "0"){
        //cout<<" Performing x2 on "<<s<<": "<<s+"0"<<nn;
        t = match(s + "0", dist, op, shift+1);
    }

    if(t > 0 && r > 0){
        if(t > r) return r;
        else return t;
    } else if(t > 0){
        return t;
    } else {
        return r;
    }
}

int match(string start){
    int d = 1;
    for(int j = 1; j < start.size(); j++){
        if(start[j-1] != start[j]){
            d++;
        }
    }
    //cout<<" Matching: "<<start << " to " << e<<nn;
    return match(start, d, 0, 0);
}

int v2(){
    int T = 0; 
    cin>>T;
    for(int i = 1; i <= T; i++){
        string start;
        cin>>start>>e;
        ed = 0;
        for(int i = 0; i < e.size(); i++){
            if(i != 0 && e[i] != e[i-1]) ed++;
        }
        
        se.clear();

        int op = match(start);

        if(op == -1){
            cout<<"Case #" <<i<<": IMPOSSIBLE"<<nn;
        } else {
            cout<<"Case #" <<i<<": "<<op<<nn;
        }
    }

    return 0;
}

void v3(){
    int T = 0; 
    cin>>T;
    for(int i = 1; i <= T; i++){
        string start;
        cin>>start>>e;
        ed = 0;
        for(int i = 0; i < e.size(); i++){
            if(i != 0 && e[i] != e[i-1]) ed++;
        }
        
        int d = 1;
        for(int j = 1; j < start.size(); j++){
            if(start[j-1] != start[j]){
                d++;
            }
        }

        if(d < ed){
            cout<<"Case #" <<i<<": IMPOSSIBLE"<<nn;
            continue;
        }

        int count = 0;
        for(int j = min(e.size(),start.size()); j > 0; j--){
            if(e.substr(0,j) == start.substr(start.size()-j,j)){
                count = e.size()-j + start.size()-j;
                break;
            }
        }

        start = n(start);
        for(int j = min(e.size(),start.size()); j > 0; j--){
            if(e.substr(0,j) == start.substr(start.size()-j,j)){
                int t = e.size()-j + start.size()-j;
                if(t < count) count = t;
                break;
            }
        }

        cout<<"Case #" <<i<<": "<<count<<nn;
    }
}

int main(){
    v2();
    return 0;
}

