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

class point{
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

    double magnitude(){
        return sqrt(x * x + y * y);
    }

    double dot(point& p){
        return x * p.x + y * p.y;
    }

    double cross(point& p){
        return x * p.y - y * p.x;
    }
    
    struct point left;
    struct point right;
    double area;
    int index;

    void setLeft(point& l){
        left = l;
    }

    void setRight(point& r){
        right = r;
    }

    void recalculate(){
        point vL = left-this;
        point vR = right - this;

        area = 0.5 * abs(vR.cross(vL));
    }

    double getArea(){
        return area;
    }
};
struct pComp{
    inline bool operator()(const point& p1, const point& p2){
        return p1.getArea() >= p2.getArea();
    }
};
// -------------------SOLUTION--------------------//
int solve(){

    int n, m;
    cin>>n>>m;
    V<point> points(n+1);
    for(int i = 0; i < n+1; i++){
        cin>>points[i];
        points[i].index = i;
    }

    set<point, pComp> s;

    for(int i = 1; i < n; i++){
        points[i].setRight(points[i+1]);
        points[i].setLeft(points[i-1]);
        points[i].recalculate();
        s.insert(points[i]);
    }
    
    point cur;
    int t = n;
    while((t--)-m){
        cur = *(s.begin());
        s.erase(cur);
        if(cur.left.index != 0){
            s.erase(cur.left);
            cur.left.setRight(cur.right);
            cur.left.recalculate();
            s.insert(cur.left);
        }
        if(cur.right.index != n){
            s.erase(cur.right);
            cur.right.setLeft(cur.left);
            cur.right.recalculate();
            s.insert(cur.right);
        }
        cout<<cur.index<<nn;
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

