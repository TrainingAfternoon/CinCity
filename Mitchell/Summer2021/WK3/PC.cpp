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

void p(int i){
    if(i == 0) cout<<"GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!"<<nn;
    else if(i == 1) cout<<"RECOUNT!"<<nn;
    else cout<<"PATIENCE, EVERYONE!"<<nn;
}

// -------------------SOLUTION--------------------//
int solve(){

    ll ncr[51][51];
    ncr[0][0] = 1;
    for(int i = 1; i < 51; i++){
        ncr[i][0] = 1;
        ncr[i][i] = 1;
        for(int j = 1; j < i; j++){
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
            //cout<<ncr[i][j]<<" ";
        }
        //cout<<nn;
    }

    int t;
    cin>>t;

    for(int i = 0; i < t; i++){
        int n, v1, v2, w;
        cin>>n>>v1>>v2>>w;
        int remaining = n-v1-v2;
        double total = pow(0.5,remaining);
        int toWin = n/2+1 - v1;
        if(toWin <= 0) p(0);
        //else if(v2 > n/2) p(1);
        else if(v2 >= (n/2 + (n&1))) p(1);
        else {
            int m = remaining;
            ll sum = 0l;
            int start = remaining - toWin + 1;
            while(start-- > 0){
                sum += ncr[remaining][m--];
            }
            double prob = total * sum;
            //cout<<sum<<" "<<prob<<" ";
            if(prob * 100 > w) p(0);
            else p(2);
        }
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

