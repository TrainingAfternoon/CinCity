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

    int n;
    vpii fav;
    cin>>n;
    int j;
    for(int i = 0; i < n; i++){
        cin>>j;
        fav.pb(mp(j, i+1));
        //cout<<fav[i].first<<nn;
    }
//    for(int i = 0; i< n; i++){
//        cout<<fav[i].first<<" ";
//    }
//    cout<<nn;

    int index = 0;
    int cur;

    while(n!=1){
        //cout<<"at index "<<index<<" w/ fav num "<<fav[index].first<<nn;
        pii p = fav[index];
        cur = ((p.first)-1) % n;
        index += cur;
        index = index%n;
        //cout<<index<<nn;

        fav.erase(fav.begin() + index);

        n--;
        if(index == n) index = 0;
    }
    cout<<fav[0].second;

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

