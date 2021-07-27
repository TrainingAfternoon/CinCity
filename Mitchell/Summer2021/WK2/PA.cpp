#include <bits/stdc++.h>

// var types
#define ll long long
#define ld long double
#define nn '\n'
#define pb push_back
#define mp make_pair

// collection shorthand
#define V vector
#define vi V<int>
#define vll V<ll> #define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>

// loops
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define in_map(m,e) (m.find(e) == m.end())
#define findchar(s,c) s.find(c)==string::npos?-1:s.find(c);

using namespace std;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// -------------------SOLUTION--------------------//
int solve(){

    string name, start, born;
    int n, year, course;
    cin>>n;
    while(n--){
        cin>>name>>start>>born>>course;
        cout<<name<<" ";
        if(stoi(start.substr(0,4)) >= 2010 || stoi(born.substr(0,4)) >= 1991){
            cout<<"eligible"<<nn;
        } else if(course > 40){
            cout<<"ineligible"<<nn;
        } else {
            cout<<"coach petitions"<<nn;
        }
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

