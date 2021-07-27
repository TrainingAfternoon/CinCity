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

struct point{
    double x, y;

    point(){
        x = 0;
        y = 0;
    }

    point(double _x, double _y){
        x = _x;
        y = _y;
    }

    friend istream &operator>>( istream& input, point& P){
        input>>P.x>>P.y;
        return input;
    }

    friend ostream &operator<<( ostream& output, point& P){
        output<<"("<<P.x<<","<<P.y<<")";
        return output;
    }

    double dist(point& p){
        return sqrt(pow(p.x-x, 2) + pow(p.y-y, 2));
    }
    
    point operator-(point& p){
        point newPoint(x - p.x, y - p.y);
        return newPoint;
    }

    double dot(point& p){
        return x * p.x + y * p.y;
    }
};

struct line{
    point p;
    point vel;

    line(point& _p, point& _vel){
        p = _p;
        vel = _vel;
    }


    point intersection(line& l){
        double a1 = -1 * vel.y;
        double b1 = vel.x;
        double c1 = -1 * p.y * vel.x + p.x * vel.y; 
        double a2 = -1 * l.vel.y;
        double b2 = l.vel.x;
        double c2 = -1 * l.p.y * l.vel.x + l.p.x * l.vel.y; 
        double x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
        double y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
        point r(x,y);
        return r;
    }

    point closestToPoint(point& op){
        point perpVel(vel.y, -1 * vel.x);
        line l(op, perpVel);
        return intersection(l);
    }
};

line from2Points(point& to, point& from){
    point v(to.x - from.x, to.y - from.y);
    line r(to, v);
    return r;
}
// -------------------SOLUTION--------------------//
int solve(){
    //point p1, p2, p3, v, t;
    double r;
    //cin>>p1>>p2>>p3>>v>>r;
    double x, y;
    cin>>x>>y;
    point p1(x,y);
    cin>>x>>y;
    point p2(x,y);
    cin>>x>>y;
    point p3(x,y);
    cin>>x>>y;
    point v(x,y);
    cin>>r;

    line l1(p1, v);
    point hit2 = l1.closestToPoint(p2);
    point hit3 = l1.closestToPoint(p3);
    point t = p2-p1;
    //cout<<t<<nn;
    double dot12 = v.dot(t);
    //cout<<dot12<<nn;
    t = p3-p1;
    //cout<<t<<nn;
    double dot13 = v.dot(t);
    //cout<<dot13<<nn;
    //cout<<hit2.dist(p2)<<nn;
    //cout<<hit3.dist(p3)<<nn;
    if( p1.dist(p2) < p1.dist(p3)){
        if(hit2.dist(p2) < 2 * r && dot12 > 0){
            double backD = sqrt(pow(2 * r, 2) - pow(hit2.dist(p2), 2));
            double vLength = sqrt(pow(v.x,2) + pow(v.y,2));
            double x = hit2.x - backD * (v.x / vLength);
            double y = hit2.y - backD * (v.y / vLength);
            point center(x,y);
            line l2 = from2Points(p2, center);
            hit3 = l2.closestToPoint(p3);
            t = p3-p2;
            double dot23 = l2.vel.dot(t);
            if(hit3.dist(p3) < 2 * r && dot23 > 0){
                cout<<1<<nn;
            } else {
                cout<<3<<nn;
            }
        } else if(hit3.dist(p3) < 2 * r && dot13 > 0){
            double backD = sqrt(pow(2 * r, 2) - pow(hit3.dist(p3), 2));
            double vLength = sqrt(pow(v.x,2) + pow(v.y,2));
            double x = hit3.x - backD * (v.x / vLength);
            double y = hit3.y - backD * (v.y / vLength);
            point center(x,y);
            line l2 = from2Points(p3, center);
            hit2 = l2.closestToPoint(p2);
            t = p2-p3;
            double dot32 = l2.vel.dot(t);
            if(hit2.dist(p2) < 2 * r && dot32 > 0){
                cout<<2<<nn;
            } else {
                cout<<4<<nn;
            }
        } else {
            cout<<5<<nn;
        }
    } else {
        if(hit3.dist(p3) < 2 * r && dot13 > 0){
            double backD = sqrt(pow(2 * r, 2) - pow(hit3.dist(p3), 2));
            double vLength = sqrt(pow(v.x,2) + pow(v.y,2));
            double x = hit3.x - backD * (v.x / vLength);
            double y = hit3.y - backD * (v.y / vLength);
            point center(x,y);
            line l2 = from2Points(p3, center);
            hit2 = l2.closestToPoint(p2);
            t = p2-p3;
            double dot32 = l2.vel.dot(t);
            if(hit2.dist(p2) < 2 * r && dot32 > 0){
                cout<<2<<nn;
            } else {
                cout<<4<<nn;
            }
        } else if(hit2.dist(p2) < 2 * r && dot12 > 0){
            double backD = sqrt(pow(2 * r, 2) - pow(hit2.dist(p2), 2));
            double vLength = sqrt(pow(v.x,2) + pow(v.y,2));
            double x = hit2.x - backD * (v.x / vLength);
            double y = hit2.y - backD * (v.y / vLength);
            point center(x,y);
            line l2 = from2Points(p2, center);
            hit3 = l2.closestToPoint(p3);
            t = p3-p2;
            double dot23 = l2.vel.dot(t);
            if(hit3.dist(p3) < 2 * r && dot23 > 0){
                cout<<1<<nn;
            } else {
                cout<<3<<nn;
            }
        } else {
            cout<<5<<nn;
        }
    }
    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

