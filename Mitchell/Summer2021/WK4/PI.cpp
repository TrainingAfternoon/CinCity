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

int pal(int i){
    int one, ten, hundred;
    i = i%1000;
    one = i%10;
    ten = (i/10)%10;
    hundred = (i/100);
    return 1000 * i + 100 * one  + 10 * ten+ hundred ;
}

// -------------------SOLUTION--------------------//
int solve(){

    int N, i, o;
    cin>>N;
    int f, t;
    int fMin;

    for(int x = 0; x < N; x++){
        cin>>o;
        i=o/1000;
        fMin = 1e9;
        f = -1;

        for(int p = -1; p <= 1; p++){
            t = pal(i + p);
            int min = abs(o-t);
            if(min < fMin){
                fMin = min;
                f = t;
            }
        }
        cout<<f<<nn;
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

