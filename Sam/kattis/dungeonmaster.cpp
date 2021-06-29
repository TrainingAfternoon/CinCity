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
#define rt recursive_traverse
int abs_min;

void recursive_traverse(char*** grid, int l, int r, int c, int cl, int cr, int cc, set<tuple<int,int,int>> visited, int min) {
    /*if(cl == l || cr == r || cc == c || grid[cl][cr][cc] == '#') {
        return 0;
    }
    if(grid[cl][cr][cc] == 'E') {
        return INT_MAX;
    }
    return rt(grid, l, r, c, cl+1, cr, cc) + rt(grid, l, r, c, cl, cr+1, cc) + rt(grid, l, r, c, cl, cr, cc+1);
    */
    if(cl < l && cr < r && cc < c && cl >= 0 && cr >= 0 && cc >= 0 && grid[cl][cr][cc] != '#' && visited.find(tuple<int,int,int>{cl,cr,cc}) == visited.end()) {
        visited.insert(tuple<int,int,int>{cl,cr,cc});
        //cout << cl << " " << cr << " " << cc << " " << grid[cl][cr][cc] << " " << min << endl;
        if(grid[cl][cr][cc] == 'E' && min < abs_min) { abs_min = min; } //return 1;
        rt(grid,l,r,c,cl+1,cr,cc,visited,min+1);
        rt(grid,l,r,c,cl,cr+1,cc,visited,min+1);
        rt(grid,l,r,c,cl,cr,cc+1,visited,min+1);
        rt(grid,l,r,c,cl-1,cr,cc,visited,min+1);
        rt(grid,l,r,c,cl,cr-1,cc,visited,min+1);
        rt(grid,l,r,c,cl,cr,cc-1,visited,min+1);

        /*if(rt(grid,l,r,c,cl+1,cr,cc,visited,min+1)) {
            cout << "triggered" << min << endl;
            return min+1;
        }
        if(rt(grid,l,r,c,cl,cr+1,cc,visited,min+1)) {
            return min+1;
        }
        if(rt(grid,l,r,c,cl,cr,cc+1,visited,min+1)) return min+1;
        if(rt(grid,l,r,c,cl-1,cr,cc,visited,min+1)) {
            return min+1;
        }
        if(rt(grid,l,r,c,cl,cr-1,cc,visited,min+1)) {
            return min+1;
        }
        if(rt(grid,l,r,c,cl,cr,cc-1,visited,min+1)) return min+1;
        //return (rt(grid,l,r,c,cl+1,cr,cc,visited,min+1) || rt(grid,l,r,c,cl,cr+1,cc,min+1) || rt(grid,l,r,c,cl,cr,cc+1,min+1)) ? min : -1;*/
    }
    //return 0;
}

int traverse(char*** grid, int l, int r, int c, int sl, int sr, int sc) {
    abs_min = INT_MAX;
    set<tuple<int,int,int>> visited;
    recursive_traverse(grid, l, r, c, sl, sr, sl, visited, 0);
    return abs_min;
}

int main(){
    fastinput();

    //---------SOLUTION----------//
    //Ohhhh, this is insideous. 3d graph traversal
    int l, r, c;
    cin >> l >> r >> c;
    do { 
        int sl, sr, sc;
        char*** grid = new char**[l];
        repi(l) {
            grid[i] = new char*[r];
            repj(r) {
                grid[i][j] = new char[c];
                repk(c) {
                    cin >> grid[i][j][k];
                    if(grid[i][j][k] == 'S') {
                        sl = i;
                        sr = j;
                        sc = k;
                    }
                }
            }
            //TODO: maybe deal with the separating lines?
        }

        /*repi(l) {
            repj(r) {
                repk(c) {
                    cout << grid[i][j][k];
                }
                cout << endl;
            }
        }*/
        
        //int minutes = -1;
        int minutes = traverse(grid, l, r, c, sl, sr, sc);
        //cout << minutes << endl;
        if(minutes == INT_MAX) {
            cout << "Trapped!" << endl;
        } else {
            cout << "Escaped in " << minutes << " minute(s)." << endl;
        }

        repi(l) {
            repj(r) {
                delete grid[i][j];
            }
        }
        delete grid;
        cin >> l >> r >> c;
    } while(l != 0 && r != 0 && c != 0);
    return 0;
}
