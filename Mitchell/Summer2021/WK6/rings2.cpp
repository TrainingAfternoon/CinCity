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
#define vll V<ll> 
#define vd V<double>
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
    int ring;
    int x;
    int y;
};
struct pComp{
    bool operator() (point& p1, point& p2){
        return p1.ring >= p2.ring;
    }
};
// -------------------SOLUTION--------------------//
int solve(){

    int n, m;
    cin>>n>>m;
    V<vi> tree;
    vi t1(m+2, 0);
    tree.pb(t1);

    string row;
    priority_queue<point, V<point>, pComp> pq;
//    point p1 = {1, 0, 0};
//    point p2 = {0, 0, 0};
//
//    pq.push(p1);
//    pq.push(p2);
//    cout<<pq.top().ring<<nn;
    for(int i = 0; i < n; i++){
        cin>>row;
        vi cur;
        cur.pb(0);
        for(int j = 0; j < m; j++){
            cur.pb(row[j] == '.' ? 0 : -1);
        }
        cur.pb(0);
        tree.pb(cur);
    }
    vi t2(m+2, 0);
    tree.pb(t2);


    m+=2;
    n+=2;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(tree[i][j] == 0) pq.push(point{0, i, j});
//    for(vi row : tree){
//        for(int i : row) cout<<i<<" ";
//        cout<<nn;
//    }

    int cur;
    while(!pq.empty()){
        point p = pq.top();
        pq.pop();
        cur = p.ring;

        for(int i = -1; i < 2; i+=2){
            if(p.x + i >= 0 && p.x + i < n && p.y >= 0 && p.y < m){
                if(tree[p.x+i][p.y] == -1){
                    tree[p.x+i][p.y] = p.ring+1;
                    pq.push(point{p.ring + 1, p.x + i, p.y});
                }
            }
        }

        for(int i = -1; i < 2; i+=2){
            if(p.x>= 0 && p.x< n && p.y + i >= 0 && p.y + i < m){
                if(tree[p.x][p.y+i] == -1){
                    tree[p.x][p.y+i] = p.ring+1;
                    pq.push(point{p.ring + 1, p.x, p.y + i});
                }
            }
        }
//        cout<< "working on point "<<p.x<<" "<<p.y<<" with ring "<<p.ring<<nn;
//    bool three = cur >=10;
//    int i;
//    string output;
//    for(int k = 0; k < n; k++){
//        for(int j = 0; j < m; j++){
//            i = tree[k][j];
//            cout<<".";
//            if(i == 0){
//                if(three) cout<<"..";
//                else cout<<".";
//            } else if(i < 10){
//                if(three) cout<<".";
//                cout<<i;
//            } else {
//                cout<<i;
//            }
//            cout<<output;
//        }
//        cout<<nn;
//    }
//    cout<<nn;
    }



    bool three = cur >=10;
    int i;
    string output;
    for(int k = 1; k < n-1; k++){
        for(int j = 1; j < m-1; j++){
            i = tree[k][j];
            cout<<".";
            if(i == 0){
                if(three) cout<<"..";
                else cout<<".";
            } else if(i < 10){
                if(three) cout<<".";
                cout<<i;
            } else {
                cout<<i;
            }
            cout<<output;
        }
        cout<<nn;
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

