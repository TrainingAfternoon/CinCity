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

struct trie {
    int instances;
    char letter;
    trie* nextLetter[52];

    trie(char l){
        letter = l;
    }

    void append(char l){
    }
    trie& addNext(char l){
        trie* tm(l);
        if(l >= 'a' && l <= 'z'){
            nextLetter[l-'a'] = tm;
        } else {
            nextLetter[l-'A'+26] = tm;
        }
        return *t;
    }
};

// -------------------SOLUTION--------------------//
int solve(){

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

