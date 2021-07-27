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

int power(int a, int n, int mod) {int p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;} 
// -------------------STRUCTS---------------------//


// -------------------FUNCTIONS-------------------//
void fill(int* pat, int M, int* lps) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while(i < M){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
            //cout<<"yay! Match!"<<nn;
        } else {
            //we didn't match, big sad
            if(len != 0){
                len = lps[len-1];
                //move len back to the last successful substring
                //note how we didn't increment i
            } else {
                // still a unique string, so move on
                lps[i++] = 0;
            }
        }
    }
}


// -------------------SOLUTION--------------------//
int solve(){
//    int arr[] = {1,1,1,2,1,1,1};
//    int test[7];
//    fill(arr, 7, test);
//    for(int i = 0; i < 7; i++) cout<<test[i]<<nn;
    int N, T;
    cin>>N>>T;
    while(T--){
        int s;
        cin>>s;
        int pat[s];
        int tmp;
        for(int i = 0; i < s; i++) {
            cin>>tmp;
            pat[i] = tmp;
            //cin>>pat[s];
        }
        //for(int i = 0; i < s; i++) cout<<pat[s];
        int lps[s];
        fill(pat, s, lps);
        //int result = pow(s,s);
        int result = 0;
        //cout<<"LPS: ";
        for(int i = 0; i < s; i++){
            //cout<<lps[i]<<" ";
            result += power(N, lps[i]+1, 10000);
        }
        result %= 10000;

        if(result < 1000) cout<<"0";
        if(result < 100) cout<<"0";
        if(result < 10) cout<<"0";
        cout<<result<<nn;
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

