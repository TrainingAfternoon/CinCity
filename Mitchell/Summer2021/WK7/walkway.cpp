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
struct trap{
    int a;
    int b;
    int h;
    V<trap*> connections;
    bool used = false;
};

struct path{
    trap* next;
    int cost;
};

struct pComp{
    bool operator() (path &p1, path &p2){
        return p1.cost >= p2.cost;
    }
};

// -------------------FUNCTIONS-------------------//
int cost(trap &t){
    return (t.a + t.b) * t.h;
}


// -------------------SOLUTION--------------------//
int solve(){
    while(true){
        int n;
        cin>>n;
        if(n == 0) break;
        V<trap> traps(n);
        for(int i = 0; i < n; i++){
            int a, b, h;
            cin>>a>>b>>h;
            V<trap*> c;
            traps[i] = trap{a, b, h, c, false};
        }
        int s, e;
        cin>>s>>e;
        if(s == e){
            cout<<"0.00"<<nn;
            continue;
        }
//        V<trap*> temp1;
//        traps.pb(trap{s, 0, 0, temp1, false});

        trap *start = &(traps[n]);
        
        priority_queue<path,V<path>, pComp> pq;
        //set up connections
        for(int i = 0; i < traps.size(); i++){
            if(traps[i].a == s || traps[i].b == s) pq.push(path{&(traps[i]), cost(traps[i])});
            for(int j = i+1; j < traps.size(); j++){
                if(traps[i].a == traps[j].a 
                        || traps[i].a == traps[j].b 
                        || traps[i].b == traps[j].a 
                        || traps[i].b == traps[j].b){
                    trap *f = &(traps[i]);
                    trap *t = &(traps[j]);
                    traps[i].connections.pb(t);
                    traps[j].connections.pb(f);
                }
            }
        }
        
        //path first = {start, 0};
        //pq.push(first);
        //cout<<first.next->a<<" "<<first.next->b<<" "<<first.next->h<<nn;
        //cout<<first.next->connections.size()<<nn;

        while(!pq.empty()){
            path cur = pq.top();
            pq.pop();
            if(cur.next->a == e || cur.next->b == e){
                cout<<(cur.cost / 100)<<".";
                int cents = cur.cost % 100;
                if(cents < 10){
                    cout<<"0";
                }
                cout<<cents<<nn;
                break;
            } else if(!(cur.next->used)){
                cur.next->used = true;
                for(trap *t : cur.next->connections){
                    if(!(t->used)) pq.push(path{t, cur.cost + cost(*t)});
                }
            } 
        }
    }
    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

