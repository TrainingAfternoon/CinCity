#include <bits/stdc++.h>
#include <math.h>
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

using namespace std;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// functs
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;} 
void fastinput(){ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);}


// -------------------MAIN CODE-------------------//

int main(){
    //fastinput();

    //---------SOLUTION----------//
   
    string line;
    double S;
    int R;
     
    while(cin>>R>>S){//getline(cin,line)){
        //size_t i = line.find(' ');
        //R = stoi(line.substr(0,i));
        //S = stod(line.substr(i+2));
        //cout<<R<<" "<<S;
        double v = pow(R*(S+.16)/.067,.5);
        int _v = (int)(v+.5);
        cout<<_v<<nn;
    }

    return 0;
}

