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

struct junc {
    int min;
    V<pair<int, int>> to;
    // for the visiting,
    // 0 means not visited
    // 1 is visited, but not with a client yet
    // 2 is visited, with a client on the path
    int visited;
    int num;
    int minPath;
    bool isClient;

    junc(int i){
        to.clear();
        visited = 0;
        minPath = 0;
        num = i;
        isClient = false;
    }
    
    void addTo(int v, int w){
        to.pb(mp(v,w));
    }
};

struct jComp {
    bool operator() (junc& j1, junc& j2){
        return j1.minPath < j2.minPath;
    }
};

struct d {
    int j, path;
    bool hasClient;
};

struct dComp {
    bool operator() (const d& i1,const d& i2){
        if(i1.path == i2.path){
            return (i1.hasClient);
        }
        return i1.path > i2.path;
    }
};
// -------------------SOLUTION--------------------//
int solve(){
    int N, M, C;
    cin>>N>>M>>C;
    V<junc> j;
    for(int i = 0; i < N; i++){
        junc junct(i);
        j.pb(junct);
    }

    int c;
    for(int i = 0; i < C; i++){
        cin>>c;
        j[c].isClient = true;
    }

    int U,V,W;
    for(int i = 0; i < M; i++){
        cin>>U>>V>>W;
        j[U].addTo(V, W);
    }
    //cout<<"Done!"<<nn;

    priority_queue<d, std::vector<d>, dComp> pq;

    pq.push({0,0,false});

    int numCars = 0;
    while(!pq.empty()){
        d cur = pq.top();
        pq.pop();
        if(j[cur.j].visited == 0){
            //cout<<"visiting: "<<cur.j<<nn;
            j[cur.j].minPath = cur.path;
            if(cur.hasClient){
                j[cur.j].visited = 2;
            } else {
                if(j[cur.j].isClient){
                    numCars++;
                    j[cur.j].visited = 2;
                    cur.hasClient = true;
                }else {
                    j[cur.j].visited = 1;
                }
            }
            for( pii i : j[cur.j].to){
                pq.push({i.first, cur.path + i.second, cur.hasClient});
            }
        }
    }
    cout<<numCars<<nn;

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

