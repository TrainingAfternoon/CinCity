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
#define FOR(a) for(ll i=0;i<a;i++)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())


// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// functs
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;} 


// -------------------MAIN CODE-------------------//
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0);
    cin.tie(0);

    //---------SOLUTION----------//
    
    //Okay so basically, walk through the given string in two-frame [a,b][b,c], etc
    //If wildcard hit, [b,c][?,e], keep record of c and e (index or character?)
    //  if we just save the straight character in two diff arrays (wildcard-prefix, wildcard-suffix)
    //  we could just traverse those at the end. len(prefix) == len(suffix), or len(prefix) == len(suffix)+1
    //  Obv when we walk, we access both arrays at once and test j or c with the two characters stored
    //With two or more wildcards in sequence: [a,?][?,?][e,...]
    //  Is there a general way to design lowest cost sequence of characters given two book ends, a, e?
    //      this would work even for case 5, 
    //  So for each case we determine the lower cost combination and prioritize that just after a run
    //My gut says aho corasick for string matching because we just learned about it, but I'm not sure if that's
    //necessary for this. Actually, I really don't think it is. Rather than the matching (which is just the o(n)
    //two frame desc. above), the real trick is designing the lowest cost sequence between two bookends
    //
    //So:
    //[a,?][?,?][e,...] where a and e MIGHT exist
    //  if a == e 
    //      make a run of ? = a = e
    //  if a == null == e
    //      make a run of any
    //  if a, but no e
    //      prioritize making a run of ? = a
    //  if no a, but e
    //      prioritize making a run of ? = e
    //  if a != e [big money case right here]
    //      prime combos
    //          CJ
    //          JC
    //      secondary combos
    //          CC
    //          JJ
    //      are the four options we can make in any given two frame
    //      Since a != e, and both exist, we must have at least one instance of a prime combo
    //      We want ot prioritize making as many secondary combos as we can around this minimum of
    //      one prime combo.
    //      UNLESS: prime combo is negative, in which case we want to prioritize it
    //      Remember, we still want to fit this into a one-pass read of s
    
    //CJ, JC
    //x   y
    
    int cases;
    cin >> cases;

    int x;
    int y;
    string s;
    string substr;
    int cost;

    //Cases:
    //Start == end
    //  run
    //start != end
    //  brute force permutations
    int start = -1;
    int end = -1;
    for(int i(0); i < cases; i++) {
        cin >> x;
        cin >> y;
        cin >> s;
        cost = 0;
        start = -1;
        end = -1;
        for(int j = 0; j < s.length(); j++) {
            substr = s.substr(j, 2);
            if(substr.compare("CJ") == 0) { //CJ
                cost += x;
            } else if (substr.compare("JC") == 0) { //JC
                cost += y;
            } else {
                if(substr.substr(0, 1).compare("?") == 0) { //?*
                    if(start == -1) { //start not set
                        start = (j - 1 < 0) ? 0 : j;
                    } else if(end == -1) { //start but no end
                        end = (j + 1 == s.length()) ? j : j + 1;
                    } else { //both start and end
                        cost += getWildcards(s, start, end);
                        start = -1;
                        end = -1;
                    }
                } else { //*?

                }
            }
        }
        cout << "Case #" << (i+1) << ": " << cost << endl;
    }

    return 0;
}

int getWildcards(string s, int start, int end) {
    const char c = 'c';
    char ret[end - start];
    int cost = 0;
    if(s[start] == s[end]) {
        memcpy(ret, &c, start-end);
    } else {
        
    }
    return cost;
}
