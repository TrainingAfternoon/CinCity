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


// -------------------FUNCTIONS-------------------//


// -------------------SOLUTION--------------------//
int solve(){
    string ops[4];
    ops[0] = "+";
    ops[1] = "-";
    ops[2] = "*";
    ops[3] = "/";

    V<string> solutions(513,"no solution");

    //int s;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                int l = 4, r = 4;

                if(i == 2) l = 16;
                if(i == 3) l = 1;

                if(j == 2) {
                    l *= r;
                    r = 0;
                }
                if(j == 3){
                    l /= r;
                    r = 0;
                }

                if(k == 2) {
                    if(r == 0) l *= 4;
                    else r *= 4;
                } else if(k == 3){
                    if(r == 0) l /= 4;
                    else r /= 4;
                }


                if(i == 0) l = 4 + l;
                if(i == 1) l = 4 - l;

                if(j == 0) l += r;
                if(j == 1) l -= r;

                if(k == 0) l += 4;
                if(k == 1) l -= 4;


                //cout<<"4" + ops[i] + "4" + ops[j] + "4" + ops[k] + "4 = " + to_string(l)<<nn; 
                solutions[l + 256] = "4 " + ops[i] + " 4 " + ops[j] + " 4 " + ops[k] + " 4 = " + to_string(l); 
                
//                s = 4;
//                if(i == 2) s *= 4;
//                if(i == 3) s /= 4;
//
//                if(j == 2) s *= 4;
//                if(j == 3) s /= 4;
//
//                if(k == 2) s *= 4;
//                if(k == 3) s /= 4;
//
//
//                if(k == 0) s += 4;
//                if(k == 1) s -= 4;
//
//                if(j == 0) s += 4;
//                if(j == 1) s -= 4;
//
//                if(i == 0) s += 4;
//                if(i == 1) s = 4 - s;
//
//                solutions[s + 256] = "4" + ops[i] + "4" + ops[j] + "4" + ops[k] + "4 = " + to_string(s); 
            }
        }
    }

    int m;
    cin>>m;
    for(int i = 0; i < m; i++){

        int c;
        cin>>c;
        if(abs(c) > 256) cout<<"no solution"<<nn;
        else cout<<solutions[c + 256]<<nn;
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

