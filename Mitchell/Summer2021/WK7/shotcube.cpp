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
struct m{
    int i;
    char d;
    int p;
    V<V<bool>>* grid;
    int c;
};


struct mComp2{
    bool operator() (m &m1, m &m2){
        if(m1.p == 1) return false;
        else if(m2.p == 1) return true;
        else if(m1.p == 2) return false;
        else if(m2.p == 2) return true;
        else if(m1.c < m2.c) return false;
        else if(m1.c > m2.c) return true;
        else if(m1.p == 0) return false;
        else if(m2.p == 0) return true;
        return m1.p < m2.p;
    }
};

struct mComp{
    bool operator() (m &m1, m &m2){
        if(m1.p == 1) return false;
        else if(m2.p == 1) return true;
        else if(m1.p == 2) return false;
        else if(m2.p == 2) return true;
        else if(m1.p == 0) return false;
        else if(m2.p == 0) return true;
        return m1.p < m2.p;
    }
};

// -------------------FUNCTIONS-------------------//
void loadGrid(V<V<bool>> &grid){
    string cur;
    for(int i = 0; i < 7; i++){
        cin>>cur;
        V<bool> t;
        grid.pb(t);
        for(int j = 0; j < 7; j++){
            grid[i].pb(cur[j] == 'X');
        }
    }
}

V<m> findMoves(m &p){
    V<V<bool>> cur = *(p.grid);
    int count = p.c;
    V<m> moves;
    for(int i = 0; i < 7; i++){
        if(cur[i][0]){
            int c = 1;
            V<V<bool>> curCopy;
            for(int n = 0; n < 7; n++){
                V<bool> temp;
                for(int l = 0; l < 7; l++){
                    temp.pb(cur[n][l]);
                }
                curCopy.pb(temp);
            }
            for(int n = 1; n < 7; n++){
                if(cur[i][n]) c++;
            }
//            while(j < 7 && cur[i][j]) j++;
//            while(j < 7){
//                if(cur[i][j]) c++;
//                j++;
//            }
            moves.pb(m{i, 'E', c, curCopy, count+1});
        }
        if(cur[i][6]){
            int c = 1;
            V<V<bool>> curCopy;
            for(int n = 0; n < 7; n++){
                V<bool> temp;
                for(int l = 0; l < 7; l++){
                    temp.pb(cur[n][l]);
                }
                curCopy.pb(temp);
            }
            for(int n = 5; n >=0; n--){
                if(cur[i][n]) c++;
            }
            moves.pb(m{i, 'W', c, curCopy, count+1});
        }
        if(cur[0][i]){
            int c = 1;
            V<V<bool>> curCopy;
            for(int n = 0; n < 7; n++){
                V<bool> temp;
                for(int l = 0; l < 7; l++){
                    temp.pb(cur[n][l]);
                }
                curCopy.pb(temp);
            }
            for(int n = 1; n < 7; n++){
                if(cur[n][i]) c++;
            }
            moves.pb(m{i, 'S', c, curCopy, count+1});
        }
        if(cur[6][i]){
            int c = 1;
            V<V<bool>> curCopy;
            for(int n = 0; n < 7; n++){
                V<bool> temp;
                for(int l = 0; l < 7; l++){
                    temp.pb(cur[n][l]);
                }
                curCopy.pb(temp);
            }
            for(int n = 5; n >= 0; n--){
                if(cur[n][i]) c++;
            }
            moves.pb(m{i, 'N', c, curCopy, count+1});
        }
    }
    return moves;
}

bool makeMove(m &move){
    char d = move.d;
    int i = move.i;
    V<V<bool>> cur = *(move.grid);
    if(d == 'S'){
        int count = 1;
        int end = 1;
        while(end < 7 && cur[end][i]) {
            end++;
            count++;
        }
        if(count == 7) return false;
        while(end < 7 && !cur[end][i]) end++;
        while(count--) cur[--end][i] = true;
        while(end > 0) cur[--end][i] = false;
    } else if(d == 'N'){
        int count = 1;
        int end = 5;
        while(end >=0 && cur[end][i]) {
            end--;
            count++;
        }
        if(count == 7) return false;
        while(end >= 0 && !cur[end][i]) end--;
        while(count--) cur[++end][i] = true;
        while(end < 6) cur[++end][i] = false;
    } else if(d == 'W'){
        int count = 1;
        int end = 5;
        while(end >=0 && cur[i][end]) {
            end--;
            count++;
        }
        if(count == 7) return false;
        while(end >= 0 && !cur[i][end]) end--;
        while(count--) cur[i][++end] = true;
        while(end < 6) cur[i][++end] = false;
    } else {
        int count = 1;
        int end = 1;
        while(end < 7 && cur[i][end]) {
            end++;
            count++;
        }
        if(count == 7) return false;
        while(end < 7 && !cur[i][end]) end++;
        while(count--) cur[i][--end] = true;
        while(end > 0) cur[i][--end] = false;
    } 
    return true;
}

bool check(V<V<bool>> &grid){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(grid[i][j]){
                return grid[i+1][j]
                    && grid[i+2][j]
                    && grid[i][j+1]
                    && grid[i+1][j+1]
                    && grid[i+2][j+1]
                    && grid[i][j+2]
                    && grid[i+1][j+2]
                    && grid[i+2][j+2];
            }
        }
    }
    return false;
}

bool unique(V<V<bool>> &g1, V<V<bool>> &g2){
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            if(g1[i][j] != g2[i][j]) return true;
        }
    }
    return false;
}

ll hashGrid(V<V<bool>> &grid){
    ll h = 0;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            h |= grid[i][j] ? 1 : 0;
            if(!(i==6 && j==6)) h *= 2;
        }
    }
    return h;
}

int recurse(V<V<bool>> &grid, set<ll> &history){
    int min = -1;
//    cout<<"cur min: "<<min<<nn;
//    cout<<"cur count: "<<count<<nn;
    m first = {0, ',', 0, grid, 0};
    priority_queue<m, V<m>, mComp> moves;
    V<m> moveSet = findMoves(first);
    for(m p : moveSet){
        moves.push(p);
    }
    while(!moves.empty()){
        m p = moves.top();
        moves.pop();
        if(min >= p.c) continue;
//        V<V<bool>> cur;
//        for(int i = 0; i < 7; i++){
//            V<bool> current;
//            for(int j = 0; j < 7; j++){
//                current.pb(grid[i][j]);
//            }
//            cur.pb(current);
//        }

        bool done = makeMove(p);
        if(done){
//            printf("%i %c %i \n",p.i,p.d,p.p);
//            for(int i = 0; i < 7; i++){
//                for(int j = 0; j < 7; j++){
//                    cout<<p.grid[i][j]<<" ";
//                }
//                cout<<nn;
//            }
//            cout<<nn;
            ll h = hashGrid(p.grid);
            if(history.find(h) == history.end()){
                history.insert(h);
                if(check(p.grid)){
                    //cout<<"found solution! "<<count<<nn;
                    if(min > p.c) min = p.c;
                }  else {
                    V<m> moveSet = findMoves(p);
                    for(m pN : moveSet){
                        printf("%i %c %i \n",p.i,p.d,p.p);
                        for(int i = 0; i < 7; i++){
                            for(int j = 0; j < 7; j++){
                                cout<<pN.grid[i][j]<<" ";
                            }
                            cout<<nn;
                        }
                        cout<<nn;
                        moves.push(pN);
                    }
                }
//                bool uniq = true;
//                for(V<V<bool>> g : history){
//                    if(!unique(g, cur)){
//                        uniq = false;
//                        break;
//                    }
//                }
//                cout<<"unique: "<<uniq<<nn;
//                if(uniq){
            }
        }
    }
    return min;
}

// -------------------SOLUTION--------------------//
int solve(){
    int n;
    cin>>n;
    V<V<bool>> grid;
    while(n--){
        grid.clear();
        loadGrid(grid);
        if(check(grid)){
            cout<<0<<nn;
        } else {
            set<ll> history;
            cout<<recurse(grid, history)<<nn;
        }
//        for(int i = 0; i < 7; i++){
//            for(int j = 0; j < 7; j++){
//                cout<<grid[i][j]<<" ";
//            }
//            cout<<nn;
//        }
//        cout<<nn;
//        vpii moves = findMoves(grid);
//        for(pii p : moves){
//            printf("%i %c \n",p.first,p.second);
//            V<V<bool>> temp;
//            for(int i = 0; i < 7; i++){
//                V<bool> current;
//                for(int j = 0; j < 7; j++){
//                    current.pb(grid[i][j]);
//                }
//                temp.pb(current);
//            }
//
//            bool done = makeMove(temp, p);
//            cout<<done<<nn;
//            for(int i = 0; i < 7; i++){
//                for(int j = 0; j < 7; j++){
//                    cout<<temp[i][j]<<" ";
//                }
//                cout<<nn;
//            }
//        }
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

