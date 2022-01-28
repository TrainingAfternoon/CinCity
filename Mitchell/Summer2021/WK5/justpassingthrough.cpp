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

struct trip{
    int r;
    int c;
    int sumE;
    int numPass;
};

struct tComp{
    bool operator()(trip& t1, trip& t2){
        return t1.sumE > t2.sumE;
    }
};

struct l{
    int r;
    int c;
    int val;
    int pass;
};

// -------------------SOLUTION--------------------//
int solve(){
    V<V<l>> locations;
    int r, c, n, val;
    cin>>r>>c>>n;
    for(int i = 0; i < r; i++){
        V<l> row;
        for(int j = 0; j < c; j++){
            cin>>val;
            row.pb(l{i, j, val, 0});
        }
        locations.pb(row);
    }
    vi passLeft(c, 0);
    for(int j = c-2; j > 0; j--){
        passLeft[j] += passLeft[j+1];
        for(int i = 1; i < r-1; i++){
            val = locations[i][j].val;
            for(int k = -1; k < 2 && val != -1; k+=2){
                if(locations[i][j+k].val == -1 || locations[i][j+k].val >= val) val = -1;
                if(locations[i+k][j].val == -1 || locations[i+k][j].val <= val) val = -1;
            }
            if(val != -1){
                locations[i][j].pass = 1;
                passLeft[j]++;
            }
        }
    }


//    for(int i = 0; i < r; i++){
//        for(int j = 0; j < c; j++){
//            cout<<(locations[i][j].isPass ? "true  " : "false ")<<" ";
//        }
//        cout<<nn;
//    }
    priority_queue<trip, V<trip>, tComp> pq;
    for(int i = 0; i < r; i++){
        if(locations[i][0].val != -1)
            pq.push(trip{i, 0, locations[i][0].val, 0});
    }

    while(!pq.empty()){
        trip t = pq.top();
        //cout<<"trip at "<<t.r<<" and "<<t.c<<nn;
        pq.pop();
        if(locations[t.r][t.c].val == -1){
            continue;
        }
        if(t.c == c-1){
            // we reached the east!

            if(t.numPass == n){
                cout<<t.sumE<<nn;
                return 0;
            }
        } else {
            if(t.r > 0){
                if(locations[t.r-1][t.c+1].val != -1 && t.numPass + locations[t.r-1][t.c+1].pass <= n && t.numPass + locations[t.r-1][t.c+1].pass + passLeft[t.c+1] >= n)
                    pq.push(trip{t.r-1, t.c+1, t.sumE + locations[t.r-1][t.c+1].val, t.numPass + locations[t.r-1][t.c+1].pass});
            }
            if(t.r < r-1){
                if(locations[t.r+1][t.c+1].val != -1 && t.numPass + locations[t.r+1][t.c+1].pass <= n && t.numPass + locations[t.r+1][t.c+1].pass + passLeft[t.c+1] >= n)
                    pq.push(trip{t.r+1, t.c+1, t.sumE + locations[t.r+1][t.c+1].val, t.numPass + locations[t.r+1][t.c+1].pass});
            }
            if(locations[t.r][t.c+1].val != -1 && t.numPass + locations[t.r][t.c+1].pass <= n && t.numPass + locations[t.r][t.c+1].pass + passLeft[t.c+1] >= n)
                pq.push(trip{t.r, t.c+1, t.sumE + locations[t.r][t.c+1].val, t.numPass + locations[t.r][t.c+1].pass});
            
        }
    }
    cout<<"impossible"<<nn;

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

