#include <bits/stdc++.h>
#include <string> 
#include <vector> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <algorithm> 
#include <functional> 
#include <iostream> 
#include <sstream> 
#include <cstdio> 

// var types
#define ll long long
#define ld long double
#define nn '\n'
#define pb push_back

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>

// loops
#define WHILE(n) while(n--)
#define repi(a) for(ll i=0;i<a;i++)
#define repj(a) for(ll j = 0; j < a; j++)
#define repk(a) for(ll k = 0; k < a; k++)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define in_map(m,e) (m.find(e) == m.end())
#define findchar(s,c) s.find(c)==string::npos?-1:s.find(c);

// Methods
#define lex_com(a,b) lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())

using namespace std;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// functs
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;} 
// trim from start (in place)
static inline void ltrim(std::string &s) {s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {return !std::isspace(ch);}));}
// trim from end (in place)
static inline void rtrim(std::string &s) {s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {return !std::isspace(ch);}).base(), s.end());}
// trim from both ends (in place)
static inline void trim(std::string &s) {ltrim(s);rtrim(s);}

void fastinput(){ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);}

// -------------------MAIN CODE-------------------//
#define base const int l, const int r, const int c, const int sl, const int sr, const int sc
#define base_in l,r,c,sl,sr,sc
#define valid_in grid,l,r,c
#define coord tuple<int,int,int>

struct Node {
    coord point;
    int dist;
} typedef node;

bool valid(char ***grid, int l, int r, int c, int x, int y, int z) {
    return (x >= 0 && y >= 0 && z >= 0 && x < l && y < r && z < c && grid[x][y][z] != '#');
}

int main(){
    fastinput();

    //---------SOLUTION----------//
    int l, r, c, sl, sr, sc;
    cin >> l >> r >> c;
    
    do {
        bool ***visited = new bool**[l];
        char ***grid = new char**[l];
        coord end;
        repi(l) {
            grid[i] = new char*[r];
            visited[i] = new bool*[r];
            repj(r) {
                grid[i][j] = new char[c];
                visited[i][j] = new bool[c];
                repk(c) {
                    cin >> grid[i][j][k];
                    if(grid[i][j][k] == 'S') {
                        sl = i;
                        sr = j;
                        sc = k;
                    }
                    if(grid[i][j][k] == 'E') {
                        end = coord{i,j,k};
                    }
                }
            }
        }

        visited[sl][sr][sc] = true;
        queue<node> q;
        q.push(node{ coord{sl,sr,sc}, 0 });

        int min_dist = -1;
        while(!q.empty() && min_dist == -1) {
            node curr = q.front();
            //cout << "curr: " << get<0>(curr.point) << "," << get<1>(curr.point) << "," << get<2>(curr.point) << endl;

            if(curr.point == end) {
                min_dist = curr.dist;
            }

            q.pop();
            
            //Scan children
            //up, down, left, right, forward, back
            int bounds[3]; bounds[0] = l; bounds[1] = r; bounds[2] = c;
            int indices[3]; indices[0] = get<0>(curr.point); indices[1] = get<1>(curr.point); indices[2] = get<2>(curr.point);
            for(int i = 0; i < 3; i++) {
                for(int j = -1; j < 2; j++) {
                    //This right here is causing the segfault
                    //The array is probably storing a reference instead of a copy :(
                    indices[i] += j;
                    if(indices[i] >= bounds[i] || indices[i] < 0) {
                        indices[i] -= j;
                        continue;
                    }
                    if(grid[indices[0]][indices[1]][indices[2]] != '#' && !visited[indices[0]][indices[1]][indices[2]]) {
                        q.push(node{ coord{indices[0],indices[1],indices[2]}, curr.dist+1 });
                        visited[indices[0]][indices[1]][indices[2]] = true;
                    }
                    indices[i] -= j;
                }
            }
            /*for(int i = -1; i < 2; i++) {
                int x = u+i;
                if(x < 0 || x >= l) continue;
                for(int j = -1; j < 2; j++) {
                    int y = n+j;
                    if(y < 0 || y >= r) continue;
                    for(int k = -1; k < 2; k++) {
                        int z = o+k;
                        if(z < 0 || z >= c) continue;
                        if(grid[x][y][z] != '#' && !visited[x][y][z]) {
                            cout << "\t"<< x << " " << y << " " << z << endl;
                            q.push(node{ coord{x,y,z}, curr.dist+1 });
                            visited[x][y][z] = true;
                        }
                    }
                }
            }*/
        }

        if(min_dist == -1) {
            cout << "Trapped!" << endl;
        } else {
            cout << "Escaped in " << min_dist << " minute(s)." << endl;
        }
        cin >> l >> r >> c;
    } while(l != 0 && r != 0 && c != 0);
    return 0;
}
