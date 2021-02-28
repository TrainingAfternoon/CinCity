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

// -------------------MAIN CODE-------------------//
using namespace std;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// functs
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;} 
void fastinput(){ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);}

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

V<string> getArgs(string args){
    V<string> a;
    string cur;
    while(true){
        size_t index = args.find(',');
        if(index != string::npos){
            cur = args.substr(0,index);
            trim(cur);
            a.pb(cur);

            args = args.substr(index+1);
        } else {
            break;
        }
    }
    trim(args);
    a.pb(args);
    return a;
}

int main(){
    //fastinput();

    //---------SOLUTION----------//
    
    unordered_map<string,V<V<string>>> tests;

    //get all tests
    string line;
    V<string> args;
    size_t index;
    string test, name;
    while(getline(cin,line)){
        if(line == "") break;
        while(true){
            index = line.find(')');
            if(index != string::npos){
                //only get the current test
                test = line.substr(0, index);
                line = line.substr(index+1);

                //get the name of the test
                index = test.find('(');
                name = test.substr(0,index);
                trim(name);
                    
                //take out the name of the test, plus the (
                test = test.substr(index+1);

                //now, process the args
                args = getArgs(test);
                if(tests.find(name) == tests.end()){
                    //if it's not in the map, add
                    V<V<string>> s;
                    s.pb(args);
                    tests[name] = s;
                } else {
                    //otherwise, add to the list
                    tests[name].pb(args);
                }
            } else {
                break;
            }
        }
    }
    V<V<string>> s;
    //process each query
    while(getline(cin,line)){
        index = line.find(')');
    
        test = line.substr(0, index);
        
        //get the name of the test
        index = test.find('(');
        name = test.substr(0,index);
        trim(name);
        if(tests.find(name) == tests.end()){
            cout<<0<<nn;
            continue;
        }
            
        //take out the name of the test, plus the (
        test = test.substr(index+1);

        args = getArgs(test);

        int count = 0;
        s = tests[name];
        for(int i = 0; i < s.size(); i++){
            //check if the arguments match;
            if(s[i].size() != args.size()){
                continue;
            } else {
                //number of args match, so now check individually;
                bool match = true;
                unordered_map<string,string> vars;
                for(int j = 0; j < args.size() && match; j++){
                    name = args[j];
                    if(name == "_"){
                        continue;
                    } else if (name[0] == '_'){
                        //special case!
                        if(vars.find(name) == vars.end()){
                            vars[name] = s[i][j];
                        } else {
                            match = (s[i][j] == vars[name]);
                        }
                    } else {
                        match = (name == s[i][j]);
                    }
                }
                if(match) count++;
            }
            
        }
        cout<<count<<nn;
    }


    return 0;
}

