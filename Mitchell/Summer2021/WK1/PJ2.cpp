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
double f(double s, double t){
    if(s == 0 || t == 0) return 0;
    if((s*s+t*t) <= 1) return abs(s)*abs(t);
    return .5 * (PI/2 + (abs(s)<1 ? sqrt(pow(s,2)-pow(s,4))-acos(abs(s)) : 0) + (abs(t)<1 ? sqrt(pow(t,2)-pow(t,4))-acos(abs(t)) : 0));
}

int solve(){

//    cout<<f(-.9,-.2)<<nn;
//    cout<<f(-.9,.7)<<nn;
//    cout<<f(-.45,-.2)<<nn;
//    cout<<f(-.45,.7)<<nn;

    double p;
    int r, dx, dy, x, y;
    cin>>r>>dx>>dy>>x>>y>>p;

    V<double> areas;

//    dx /= r;
//    dy /= r;
//    x /= r;
//    y /= r;

//    cout<<dx<<" "<<dy<<" "<<x<<" "<<y<<nn<<nn;

    while(x > -r) x -= dx;
    while(y > -r) y -= dy;

//    cout<<"X: "<<x<<" Y: "<<y<<nn;

    double startY = y;

    int xs[] = {-2, x};
    int ys[] = {-2, y};

    double largest = -1000000;

    int c;

    for(x = x+dx; xs[1] < r; x+=dx){
        xs[0] = xs[1];
        xs[1] = x;

        ys[1] = startY;
        for(y = startY+dy; ys[1] < r; y+=dy){
            ys[0] = ys[1];
            ys[1] = y;

            c = 0;
            bool even;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    if(i==0 && j==0){
                        even = !((xs[i] >= 0 && ys[j] >= 0) || (xs[i]<0 && ys[j] < 0));
                    } else if((xs[i] >= 0 && ys[j] >= 0) || (xs[i]<0 && ys[j] < 0)){
                        // should be an odd region
                        if(even)c++;
                        even = false;
                    } else {
                        // should be an even region
                        if(!even)c++;
                        even = true;
                    }
                }
            }

            int changes[4][4] = {
                {1, -1, -1, 1},
                {-1, 1, -1, 1},
                {1, 1, 1, 1},
                {-1, -1, 1, 1}
            };
            int k = 0;
            double a = 0;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    double temp = f((xs[i]*1.0/r),(ys[j]*1.0/r)) * changes[c][k];
//                    cout<<"\t\tFound area: "<<temp<<" for x " << xs[i]<<" and y "<< ys[j]<<nn;
                    a+=temp;
                    k++;
                }
            }
            a = abs(a);
            //cout<<"\tChanges: "<<c<<nn;
//            cout<<"Current X: "<<x<<nn;
//            cout<<"Current Y: "<<y<<nn;
//            cout<<"\tArea: "<<a<<nn;
            if(a > 1e-10) areas.pb(a);
            if(a > largest) largest = a;
        }
    }

//    cout<<"Largest: "<<largest<<nn;

    c = 0;

    for(double a : areas){
//        cout<<a<<nn;
        if(largest*p > a) c++;
//        if(abs(a/largest-p) <= (1e-6))c++;
    }

    cout<<c<<nn;

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

