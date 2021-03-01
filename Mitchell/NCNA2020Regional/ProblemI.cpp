#include <bits/stdc++.h>
#include <cmath>
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
const double PI = M_PI;
const int MOD = 1e9 + 7;

// functs
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;} 

using namespace std;
void fastinput(){ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);}

// -------------------MAIN CODE-------------------//

int main(){
    fastinput();

    //---------SOLUTION----------//
    
    cout<<fixed<<setprecision(5);

    int n;
    double r, s, w, f, l1, l2,d;
    cin>>n>>r>>s>>w>>f>>l1>>l2;
    V<V<double>> distances;

    for(int i = 0; i< n; i++){
        V<double> t;
        distances.pb(t);
        double l = i==0? l1 : l2;
        distances[i].pb(2*PI*(r+l+(i)*w) + s*2);
        distances[i].pb(PI*(r+l+(i)*w)+s);
        distances[i].pb(PI*(r+l+(i)*w));
    }

    double x,y,_d;
    while(cin>>_d){
        cout<<_d;
        for(int i = 0; i < n; i++){
            d = _d;
            //cout<<nn;
            double _r = r+(i)*w;
            x = -.5*s;
            y = -1*_r;
            if(d<(f+.5*s)){
                //cout<<"Made first check: ";
                cout<<" "<<(f+.5*s-d)<<" "<<y;
                continue;
            } 
            d-=f+.5*s;
            //now we're at bottom left

            d-=((int)(d/distances[i][0])*distances[i][0]);
            //while(d > distances[i][0]){
            //    //cout<<"Made second check: ";
            //    d-=distances[i][0];
            //}
            //still at bottom left, just did loops
            
            bool left = true; //bottom left
            if(d >= distances[i][1]){
                //cout<<"Made third check: "; 
                d-=distances[i][1];
                y=_r;
                x=.5*s;
                left = false; //now top right
            }

            if(d>=distances[i][2]){
                //cout<<"Made straight: "; 
                d-=distances[i][2];
                y*=-1;
                //we're in the straight 
                if(left){
                    x+=d;
                } else {
                    x-=d;
                }
            } else {
                //in loop 
                //cout<<"Made loop: "; 
                
                double l = i==0 ? l1 : l2;
                double R = l+_r;
                double theta = PI/2.0-d/R;
                if(left) theta += PI;
                y = _r*sin(theta);
                x+= _r*cos(theta);
            }
            cout<<" "<<x<<" "<<y;
        }
        cout<<nn;
    }

    return 0; }

