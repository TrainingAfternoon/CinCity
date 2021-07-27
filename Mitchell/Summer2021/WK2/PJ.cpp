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

double xGivenY(pair<double, double> p1, pair<double, double> p2, double y){
    double m = (p1.second - p2.second) * 1.0 / (p1.first - p2.first);
    return (y - p1.second) / m + p1.first;
}
double areaOfPolygon(V<pair<double, double>> points){
    points.pb(points.front());
    double s1 = 0, s2 = 0;
    for(int i = 0; i < points.size()-1; i++){
        s1 += points[i].first * points[i+1].second;
    }
    for(int i = 1; i < points.size(); i++){
        s2 += points[i].first * points[i-1].second;
    }
    points.pop_back();
    return 0.5 * abs(s1-s2);
}
double bs(V<pair<double, double>> bounds, double area){
    // 0: bottom left
    // 1: bottom right
    // 2: top right
    // 3: top left
    //cout<<nn;
    //cout<<"target A"<<area<<nn;
    double h = 0, lastH = -1;
    V<pair<double,double>> d(4);
    d[0] = bounds[0];
    d[1] = bounds[1];

    while(abs(lastH-h) > 0.001){
        lastH = h;
        h = (bounds[0].second + bounds[3].second) * 0.5;
        //cout<<h<<nn;

        pair<double, double> tR = mp((bounds[1].first + bounds[2].first) * 0.5, h);
        pair<double, double> tL = mp((bounds[0].first + bounds[3].first) * 0.5, h);
        d[2] = tR;
        d[3] = tL;


        double a = areaOfPolygon(d);
        //cout<<"Area: "<<a<<nn;
        if(a == area) break;
        if(a < area) {
            bounds[1] = tR;
            bounds[0] = tL;
        } else {
            bounds[2] = tR;
            bounds[3] = tL;
        }
    }
    return h;
}

// -------------------SOLUTION--------------------//
int solve(){
    cout<<fixed<<setprecision(2);
    int N, D, L;
    cin>>N>>D>>L;
    double volCM = L*1000.0;
    double desiredA = volCM/D;
    double maxY = 0;
    V<pair<double, double>> points(N);
    for(int i = 0; i < N; i++){
        int x, y;
        cin>>x>>y;
        points[i] = mp(x,y);
        if( y > maxY ) maxY = y;
    }
    int i = 0;
    for(; points[i].second != 0; i++){
        points.pb(points[i]);
    }
    points.erase(points.begin(), points.begin()+i);
    double tA =areaOfPolygon(points);
    if( tA == 0 || desiredA == 0 ){
        cout<<0<<nn;
        return 0;
    } 
    if(tA == desiredA){
        cout<<maxY<<nn;
        return 0;
    }

//    for(pair<double, double> p : points){
//        cout<<"Points:"<<nn;
//        cout<<p.first<<" "<<p.second<<nn;
//    }
    // 0: bottom left
    // 1: bottom right
    // 2: top right
    // 3: top left
    V<pair<double, double>> bounds(4);
    int topLeft = points.size()-1;
    int topRight = 2;
    bounds[0] = points[0];
    bounds[1] = points[1];
    bounds[2] = points[topRight];
    bounds[3] = points[topLeft];

    while(true){
        if(desiredA == 0) break;
        if(bounds[2].second == bounds[3].second){
            //equal, so bump up
            double a = areaOfPolygon(bounds);
            if(a >= desiredA) break;
            desiredA-=a;
            bounds[0] = bounds[3];
            bounds[1] = bounds[2];
            bounds[2] = points[++topRight];
            bounds[3] = points[--topLeft];
        } else if(bounds[2].second < bounds[3].second){
            //right side is lower than left side, gotta change top left
            pair<double, double> temp = bounds[3];
            bounds[3] = mp(xGivenY(bounds[0], temp, bounds[2].second), bounds[2].second);
            double a = areaOfPolygon(bounds);
            if(a >= desiredA) break;
            desiredA -= a;
            bounds[0] = bounds[3];
            bounds[1] = bounds[2];
            bounds[2] = points[++topRight];
            bounds[3] = temp;

        } else {
            //left side is lower than right side
            pair<double, double> temp = bounds[2];
            bounds[2] = mp(xGivenY(bounds[1], temp, bounds[3].second), bounds[3].second);
            double a = areaOfPolygon(bounds);
            if(a >= desiredA) break;
            desiredA -= a;
            bounds[0] = bounds[3];
            bounds[1] = bounds[2];
            bounds[2] = temp;
            bounds[3] = points[--topLeft];
        }
    }
    cout<<bs(bounds, desiredA)<<nn;

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

