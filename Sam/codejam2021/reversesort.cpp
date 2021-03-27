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

int calculate_cost(vi n);
int min(vi n, int start);

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0);
    cin.tie(0);

    //---------SOLUTION----------//
    int cases;
    cin >> cases;

    int elements;
    int cost;
    string line;
    vi values;
    istringstream int_stream;
    int n;
    for(int i = 0; i < cases; i++) {
        cin >> elements;
        cin.ignore(1); //ignore nl
        getline(cin, line);
        int_stream.str(line);
        for(int j = 0; j < elements; j++) {
            int_stream >> n;
            values.push_back(n);
        }
        cost = calculate_cost(values);

        cout << "Case #" << (i+1) << ": " << cost << endl;
        values.clear();
        int_stream.clear();
    } 

    return 0;
}

int calculate_cost(vi n) {
    int j;
    int cost = 0;
    for(int i = 0; i < n.size() - 1; i++) {
        j = min(n, i);
        cost += j - i + 1;

        reverse(n.begin() + i, n.begin() + j + 1);
    }
    return cost;
}

int min(vi n, int start) {
    int min = INT_MAX;
    int minI = 0;
    int index = start;
    for(vi::iterator it = n.begin() + start; it != n.end(); index++) {
        if(*it < min) {
            min = *it;
            minI = index;
        }
        it++;
    }
    return minI;
}

