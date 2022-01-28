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


// -------------------SOLUTION--------------------//
int solve(){
    cout<<fixed<<setprecision(6);
    int m;
    cin>>m;
    bool angle[360][60][60];
    for(int i = 0; i < 360; i++)
        for(int j = 0; j < 60; j++)
            for(int k = 0; k < 60; k++)
                angle[i][j][k] = false;
    while(m--){
        int r, n, dd, dm, ds;
        cin>>r>>n>>dd>>dm>>ds;
        int d = 0, m = 0, s = 0;
        while(n-- && !angle[d][m][s]){
            angle[d][m][s] = true;
            s += ds;
            if(s >= 60){
                m++;
                s -= 60;
            }
            m += dm;
            if(m >= 60){
                d++;
                m-=60;
            }
            d += dd;
            if(d >= 360){
                d -= 360;
            }
        }
        double maxA = 0;
        double cur = 0;
        int pd = 0, pm = 0, ps = 0;
        for(d = 0; d < 360; d++){
            for(m = 0; m < 60; m++){
                for(s = 0; s < 60; s++){
                    if(angle[d][m][s]){
                        angle[d][m][s] = false;
                        cur = ((d-pd) + (m-pm)/60.0 + (s-ps)/3600.0)/360.0;
                        if(maxA < cur) maxA = cur;
                        pd = d;
                        pm = m;
                        ps = s;
                    }
                }
            }
        }
        //cout<<pd<<" "<<pm<<" "<<ps<<nn;
        cur = 1 - ((pd) + (pm)/60.0 + (ps)/3600.0)/360.0;
        if(maxA < cur) maxA = cur;
        double a = PI * r * r * maxA;
        cout<<a<<nn;
    }


    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

