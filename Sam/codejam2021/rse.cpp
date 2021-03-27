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
#define FOR(a) for(ll i=0;i<a;i++)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())


// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// functs
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;} 


// -------------------MAIN CODE-------------------//
using namespace std;

string vector_to_string(vi vector) {
    stringstream stream;
    for(vi::iterator it = vector.begin(); it != vector.end(); it++) {
        stream << *it;
    }
    return stream.str();
}

vi shuffle(vi list, int n) {
    
}

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0);
    cin.tie(0);

    //---------SOLUTION----------//
    int size;
    int cost;
    int cases;
    int magic_number;
    vi list;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        cin >> size;
        cin >> cost;
        magic_number = (size+size)-2;
        if(size-1 > cost || cost > (size+size) {
            cout << "Case #" << (i+1) << ": IMPOSSIBLE" << endl;
        } else if (cost == magic_number) {
            list(size);
            generate(list.begin(), list.end(), [n=size]() { return n--; });
            cout < "Case #" << (i+1) << ": " << vector_to_string(list) << endl;
        } else {
            generate(list.begin(), list.end(), [n=1]() { return n++; });
            shuffle(list, cost);
            cout < "Case #" << (i+1) << ": " << vector_to_string(list) << endl;
        }
    }

    return 0;
}
