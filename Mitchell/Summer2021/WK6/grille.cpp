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

void print(V<V<bool>>& grid){
    for(V<bool> row : grid){
        for(bool b : row){
            cout<<b;
        }
        cout<<nn;
    }
}
void print(V<V<char>>& grid){
    for(V<char> row : grid){
        for(char c : row){
            cout<<c;
        }
        cout<<nn;
    }
}
V<V<bool>> rotate(V<V<bool>> grid, int n){
    V<V<bool>> newGrid;
    for(int col = 0; col < n; col++){
        V<bool> curRow;
        for(int row = n-1; row >= 0; row--){
            curRow.pb(grid[row][col]);
        }
        newGrid.pb(curRow);
    }
    return newGrid;
}
void fill(V<V<char>>& grid, V<V<bool>>& holes, string message, int n){
    int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(holes[i][j]){
                grid[i][j] = message[index++];
            }
        }
    }
}
bool isFilled(V<V<char>>& grid, int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == '.') return false;
    return true;
}
void printFull(V<V<char>>& grid, int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cout<<grid[i][j];
}

// -------------------SOLUTION--------------------//
int solve(){
    int n;
    cin>>n;
    V<V<bool>> holes;
    string message;
    int numHoles = 0;
    for(int i = 0; i < n; i++){
        V<bool> row;
        cin>>message;
        for(int j = 0; j < n; j++){
            row.pb(message[j] == '.');
            if(row[j]) numHoles++;
        }
        holes.pb(row);
    }
    if(numHoles * 4 != n * n){
        cout<<"invalid grille";
        return 0;
    }
    cin>>message;
    //print(holes);
    V<V<char>> grid;
    for(int i = 0; i < n; i++){
        V<char> row;
        for(int j = 0; j < n; j++){
            row.pb('.');
        }
        grid.pb(row);
    }
    for(int i = 0; i < 4; i++){
        string cur = message.substr(0,numHoles);
        fill(grid,holes,cur,n);
        holes = rotate(holes,n);
        //print(holes);
        //cout<<nn;
        //cout<<cur<<nn;
        message = message.substr(numHoles);
    }
    //printFull(grid, n);
    if(isFilled(grid, n)){
        printFull(grid, n);
    }
    else 
    {
        cout<<"invalid grille";
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

