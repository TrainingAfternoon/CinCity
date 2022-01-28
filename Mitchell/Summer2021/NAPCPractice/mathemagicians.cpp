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
#define vii V<vi>
#define vll V<ll> 
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>

// funcs 
#define inRange(x,y,l,w) (x >= 0 && x < l && y >= 0 && y < w)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define in_map(m,e) (m.find(e) == m.end())
#define findchar(s,c) s.find(c)==string::npos?-1:s.find(c);

using namespace std;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// -------------------STRUCTS---------------------//


// -------------------FUNCTIONS-------------------//
int countSwitch(string s){
    int count = 0;
    for(int i = 0; i < s.size()-1; i++){
        count += (s[i] != s[i+1]);
    }
    count += (s[0] != s[s.size()-1]);
    return count;
}

bool group(string s){
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1]) return true;
    }
    return s[0] == s[s.size()-1];
}

// -------------------SOLUTION--------------------//
int solve(){
    int s;
    cin>>s;
    string start;
    cin>>start;
    string goal;
    cin>>goal;
    int sf, sg;
    sf = countSwitch(start);
    sg = countSwitch(goal);
    bool d = group(start);
//    cout<<sf<<nn;
//    cout<<sg<<nn;
    if(sf > sg) cout<<"yes"<<nn;
    else if(sf < sg) cout<<"no"<<nn;
    else if(start == goal) cout<<"yes"<<nn;
    else if(sf == 0 && start[0] == goal[0]) cout<<"yes"<<nn;
    else if(sf != 0 && d) cout<<"yes"<<nn;
    else cout<<"no"<<nn;
    
    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

