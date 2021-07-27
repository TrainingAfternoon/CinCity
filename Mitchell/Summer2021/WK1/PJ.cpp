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

double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}
double areaOfSegment(double x1, double y1, double x2, double y2, double r){
    double d = dist(x1, y1, x2, y2);
    double angle = 2*asin(d/2/r);
    return .5 * r * r * (angle * sin(angle));
}

double areaOfTriangle(int x[], int[] y){
    double a = dist(x[0], y[0], x[1], y[1]);
    double b = dist(x[0], y[0], x[2], y[2]);
    double c = dist(x[1], y[1], x[2], y[2]);
    double s = (a + b + c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

bool inCircle(double x, double y, double r){
    return r*r >= x*x + y*x;
}

// -------------------SOLUTION--------------------//
int solve(){
    double r, dx, dy, x, y, p;
    cin>>r>>dx>>dy>>x>>y>>p;

    V<double> areas;
    V<double> xs, ys;

    while(x > -r) x-=dx;
    while(y > -r) y-=dy;

    double startY = y;
    double lastY = y;
    double lastX = x;
    for(; x <= r; x+=dx){
        int count = 0;
        for(y = startY; y <= r; y+=dy){
            if(y > lowerY){
               // xs.clear();
               // ys.clear();

                double rightX = sqrt(r*r-y*y);

                bool upRight = inCircle(x, y, r);
                bool downRight = inCircle(x, lastY, r);
                bool upLeft = inCircle(lastX, y, r);
                bool downLeft = inCircle(lastX, lastY, r);

//                if(upRight){
//                    xs.pb(x);
//                    ys.pb(y);
//                }
//
//                if(downRight){
//                    xs.pb(x);
//                    ys.pb(lastY);
//                }
//
//                if(upLeft){
//                    xs.pb(lastX);
//                    ys.pb(y);
//                }
//
//                if(downLeft){
//                    xs.pb(lastX);
//                    ys.pb(lastY);
//                }

                double a;
                if(downLeft && upLeft && downRight && upRight){
                    a = dx * dy;
                } if(!downLeft && upLeft && downRight && upRight){ // 5 points, whack
                    double _x = {lastX, lastX, -1*(r*r-lastY*lastY)};
                    double _y = {lastY, -1(r*r-lastX*lastX), lastY};
                    a = dx * dy - areaOfTriangle(_x, _y) + areaOfSegment(_x[1], _y[1], _x[2], _y[2], r);
                } else if(downLeft && !upLeft && downRight && upRight){
                    double _x = {lastX, lastX, r*r-y*y};
                    double _y = {y, r*r-lastX*lastX, y};
                    a = dx * dy - areaOfTriangle(_x, _y) + areaOfSegment(_x[1], _y[1], _x[2], _y[2], r);
                } else if(downLeft && upLeft && !downRight && upRight){
                    double _x = {x, x, r*r-lastY*lastY};
                    double _y = {lastY, r*r-x*x, lastY};
                    a = dx * dy - areaOfTriangle(_x, _y) + areaOfSegment(_x[1], _y[1], _x[2], _y[2], r);
                } else if(downLeft && upLeft && downRight && !upRight){
                    double _x = {lastX, x, r*r-lastY*lastY};
                    double _y = {lastY, r*r-lastX*lastX, y};
                    a = dx * dy - areaOfTriangle(_x, _y) + areaOfSegment(_x[1], _y[1], _x[2], _y[2], r);
                } else if(!downLeft && !upLeft && downRight && upRight){ // 4 points, trapezoid
                } else if(!downLeft && upLeft && !downRight && upRight){
                } else if(!downLeft && upLeft && downRight && !upRight){
                } else if(downLeft && !upLeft && !downRight && upRight){
                } else if(downLeft && !upLeft && downRight && !upRight){
                } else if(downLeft && upLeft && !downRight && !upRight){
                } else if(!downLeft && !upLeft && !downRight && upRight){ // 3 points, triangle ish
                } else if(!downLeft && !upLeft && downRight && !upRight){
                } else if(!downLeft && upLeft && !downRight && !upRight){
                } else if(downLeft && !upLeft && !downRight && !upRight){
                }
                areas.pb(a);
                count++;
            }
            lastY = y;
        }
        if(y-dx < upperY){
            //current spot
            xs.pb(x);
            ys.pb(y);

            if(count==0){
                xs.pb(x);
                ys.pb(lowerY);
            }
        }
        lastX = x;
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

