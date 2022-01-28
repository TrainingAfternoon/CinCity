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

// -------------------SOLUTION--------------------//
//int divisor(int p){
//    if((p&1)==0) return 2;
//    for(int i = 3; i <= sqrt(p); i+=2){
//
//    }
//}

int solve(){

    int t;
    string player;
    int bob;
    cin>>t;
    int n;
    for(int x = 0; x < t; x++){
        cin>>n>>player;
        bob = (player == "Bob");

        int f = 0;
        int amount[2] = {0, 0};
        //find primes
        int cur = 2;
        while(n!=1 && f < 2){
            if(cur > sqrt(n)){
                amount[f++] = 1;
                n = 1;
            } else if((n%cur) == 0){
                //cout<<"\t"<<cur;
                while((n%cur) == 0) {
                    n /= cur;
                    amount[f]++;
                }
                f++;
            }
            cur += (cur == 2 ? 1 : 2);
        }
        //cout<<" N:"<<n<<nn;
        if((n == 1) && ((f == 1) || abs(amount[0] - amount[1]) <= 1)){
            int total = amount[0] + amount[1];
            bool other = ((total % 2) == 0);

            if(other){
                cout<<(bob?"Alice":"Bob")<<nn;
            } else {
                cout<<(bob?"Bob":"Alice")<<nn;
            }
        } else {
            cout<<"tie"<<nn;
        }
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

