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

// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// functs
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;} 


// -------------------MAIN CODE-------------------//
using namespace std;

void fastinput(){ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);}

struct myclass1 {
  bool operator() (pair<string,string> i, pair<string, string> j) { 
       string n1 = i.first;
        string n2 = j.first;
        transform(n1.begin(), n1.end(), n1.begin(),[](unsigned char c){ return std::tolower(c); });
        transform(n2.begin(), n2.end(), n2.begin(),[](unsigned char c){ return std::tolower(c); });
      return (n1<n2);
  }
} mysort1;

struct myclass2 {
  bool operator() (pair<string,string> i, pair<string, string> j) { 
        string n1 = i.second;
        string n2 = j.second;
        transform(n1.begin(), n1.end(), n1.begin(),[](unsigned char c){ return std::tolower(c); });
        transform(n2.begin(), n2.end(), n2.begin(),[](unsigned char c){ return std::tolower(c); });
      return (n1<n2);
  }
} mysort2;
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



int main(){
    //fastinput();

    //---------SOLUTION----------//
    

    string line;
    //map<string, string> contacts;
    V<pair<string,string>> contacts;
    pair<string, string> c;
    string fname, lname, email;
    size_t i;
    string t = "\t";
    string s = " ";
    while(getline(cin,line)){
        if(line == "") break;
        
        i = line.find(t);
        if(i == string::npos) i = line.find(s);
        fname = line.substr(0,i);
        line = line.substr(i);
        trim(line);


        i = line.find(t);
        if(i == string::npos) i = line.find(s);
        lname = line.substr(0,i);
        email = line.substr(i);

        trim(fname);
        trim(lname);
        trim(email);
            
        //cout<<email<<" "<<fname<<" "<<lname<<nn;
        c = {email, (lname+" "+ fname)};
        contacts.pb(c);
    }


    V<pair<string,string>> outside;
    while(getline(cin,line)){
        if(line == "") break;
 
        i = line.find(t);
        if(i == string::npos) i = line.find(s);
        fname = line.substr(0,i);
        line = line.substr(i);
        trim(line);

        i = line.find(t);
        if(i == string::npos) i = line.find(s);
        lname = line.substr(0,i);
        email = line.substr(i);

        trim(fname);
        trim(lname);
        trim(email);
            
        c = {email, lname+" " + fname};
        outside.pb(c);
    }

    string n1, n2;
    sort(contacts.begin(), contacts.end(),mysort2);
    sort(outside.begin(), outside.end(), mysort2);

    int oi = 0;
    for(int i = 0; i < contacts.size(); i++){
        if(oi<0)oi=0;
        n1 = contacts[i].second;
        n2 = outside[oi].second;
        transform(n1.begin(), n1.end(), n1.begin(),[](unsigned char c){ return std::tolower(c); });
        transform(n2.begin(), n2.end(), n2.begin(),[](unsigned char c){ return std::tolower(c); });

        //cout<<"\t"<<n1<<"\t"<<n2<<nn;
        while(oi < outside.size()-1 && n1 > n2) {
            oi++;
            n2 = outside[oi].second;
            transform(n2.begin(), n2.end(), n2.begin(),[](unsigned char c){ return std::tolower(c); });
            //cout<<"\t"<<n1<<"\t"<<n2<<nn;
        }

        //cout<<nn<<"\t"<<n1<<"\t"<<n2<<nn;
        if(oi >= outside.size()) break;
        if(n1 == n2){
            contacts.erase(contacts.begin() + i--);
            outside.erase(outside.begin() + oi--);
        }
    }

    sort(contacts.begin(), contacts.end(),mysort1);
    sort(outside.begin(), outside.end(), mysort1);

    oi = 0;
    for(int i = 0; i < contacts.size(); i++){
        if(oi<0)oi=0;
        n1 = contacts[i].first;
        n2 = outside[oi].first;
        transform(n1.begin(), n1.end(), n1.begin(),[](unsigned char c){ return std::tolower(c); });
        transform(n2.begin(), n2.end(), n2.begin(),[](unsigned char c){ return std::tolower(c); });
        while(oi < outside.size() && n1 > n2) {
            oi++;
            n2 = outside[oi].first;
            transform(n2.begin(), n2.end(), n2.begin(),[](unsigned char c){ return std::tolower(c); });
        }
        if(oi >= outside.size()) break;
        if(n1 == n2){
            contacts.erase(contacts.begin() + i--);
            outside.erase(outside.begin() + oi--);
        }
    }

    if(outside.size() == 0 && contacts.size() == 0){
        cout<<"No mismatches."<<nn;
    } else {
        for(int i = 0; i < contacts.size(); i++){
            cout<<"I " <<contacts[i].first<<" "<<(contacts[i].second)<<nn;
        }
        for(int i = 0; i < outside.size(); i++){
            cout<<"O " <<outside[i].first<<" "<<(outside[i].second)<<nn;
        }
    }

    return 0;
}

