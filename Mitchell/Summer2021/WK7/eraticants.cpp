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
struct spot{
    bool n = false;
    bool s= false;
    bool e= false;
    bool w= false;
    spot* north;
    spot* south;
    spot* east;
    spot* west;
    bool last = false;
    bool used = false;
};


// -------------------FUNCTIONS-------------------//


// -------------------SOLUTION--------------------//
int solve(){

    int _n;
    cin>>_n;
    while(_n--){
        int _s;
        cin>>_s;

        spot original;

        spot *cur = &original;

        char c;
        for(int i = 0; i < _s; i++){
            spot *next, temp;
            next = &temp;
            cin>>c;
            if(c=='S'){
                if(cur->s){
                    cur = cur->south;
                } else {
                    cur->s = true;
                    next->n = true;
                    cur->south = next;
                    next->north = cur;
                    cur = next;
                }
            } else if (c=='N'){
                if(cur->n){
                    cur = cur->north;
                } else {
                    cur->n = true;
                    next->s = true;
                    cur->north = next;
                    next->south = cur;
                    cur = next;
                }
            } else if (c=='E'){
                if(cur->e){
                    cur = cur->east;
                } else {
                    cur->e = true;
                    next->w = true;
                    cur->east = next;
                    next->west = cur;
                    cur = next;
                }
            } else if (c=='W'){
                if(cur->w){
                    cur = cur->west;
                } else {
                    cur->w = true;
                    next->e = true;
                    cur->west = next;
                    next->east = cur;
                    cur = next;
                }
            }
        }
        cur->last = true;

        //BFS
        V<spot*> first;
        first.pb(&original);
        bool found = false;
        int count = 0;
        while(!found){
            V<spot*> next;
            //cout<<"Going through "<<first.size()<<" spots"<<nn;
            count++;
            for(int i = 0; i < first.size() && !found; i++){
                cur = first[i];
                cur->used = true;
                if(cur->last){
                    found = true;
                    cout<<count<<nn;
                }
                if(cur->n && !(cur->north->used)) next.pb(cur->north);
                if(cur->s && !(cur->south->used)) next.pb(cur->south);
                if(cur->e && !(*(cur->east)).used) next.pb(cur->east);
                if(cur->w && !(*(cur->west)).used) next.pb(cur->west);
            }
            first = next;
        }
    }
//    int n;
//    cin>>n;
//    while(n--){
//        vii map(140);
//        for(int i = 0; i < 140; i++){
//            vi cur(140,-1);
//            map[i] = cur;
//        }
//        map[70][70] = 0;
//        int s;
//        cin>>s;
//
//        int cur = 0, x = 70, y = 70;
//
//        char c;
//        for(int i = 0; i < s; i++){
//            cin>>c;
//            if(c=='S'){
//                y++;
//            } else if (c=='N'){
//                y--;
//            } else if (c=='E'){
//                x++;
//            } else if (c=='W'){
//                x--;
//            }
//            if(map[x][y] == -1){
//                map[x][y] = ++cur;
//            } else {
//                if(cur < map[x][y]) map[x][y] = ++cur;
//                else cur = map[x][y];
//            }
//            cout<<cur<<nn;
//        }
//        for(int i = 70; i < 73; i++){
//            for(int j = 70; j < 73; j++){
//                cout<<map[i][j]<<" ";
//            }
//            cout<<nn;
//        }
//        cout<<cur<<nn;
//    }

    return 0;
}

void s2(){
    int n;
    cin>>n;
    while(n--){
        V<V<spot>> map(122);
        for(int i = 0; i < 122; i++){
            V<spot> cur(122);
            map[i] = cur;
        }
        int s;
        cin>>s;

        int x = 61, y = 61;

        char c;
        for(int i = 0; i < s; i++){
            cin>>c;
            if(c=='S'){
                map[x][y].s = true;
                y++;
                map[x][y].n = true;
            } else if (c=='N'){
                map[x][y].n = true;
                y--;
                map[x][y].s = true;
            } else if (c=='E'){
                map[x][y].e = true;
                x++;
                map[x][y].w = true;
            } else if (c=='W'){
                map[x][y].w = true;
                x--;
                map[x][y].e = true;
            }
            //cout<<cur<<nn;
        }
        //cout<<cur<<nn;
        map[x][y].last = true;

        //BFS
        vpii f;
        f.pb(mp(61,61));
        bool found = false;
        int count = 0;
        while(!found){
            vpii next;
            //cout<<"Going through "<<first.size()<<" spots"<<nn;
            for(int i = 0; i < f.size() && !found; i++){
                pii p = f[i];
                spot *cur = &(map[p.first][p.second]);
                if(!(cur->used)){
                    cur->used = true;
                    if(cur->last){
                        found = true;
                        //cout<<"found at"<<p.first<<" and "<<p.second<<nn;
                        cout<<count<<nn;
                    }
                    if(cur->e) next.pb(mp(p.first+1, p.second));
                    if(cur->w) next.pb(mp(p.first-1, p.second));
                    if(cur->s) next.pb(mp(p.first, p.second+1));
                    if(cur->n) next.pb(mp(p.first, p.second-1));
                }
            }
            count++;
            f = next;
        }
    }
}

// -------------------MAIN CODE-------------------//
int main(){
    s2();
    return 0;
}

