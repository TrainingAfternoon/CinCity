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
#define minimum(a) *min_element(a.id.begin(), a.id.end())
#define maximum(a) *max_element(a.id.begin(), a.id.end())

//local
#define sift(q) while(!q.empty() && players.at(q.top().id)) { q.pop(); }


// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// functs
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;} 


// -------------------MAIN CODE-------------------//
using namespace std;
const char *split = " ";

struct Player {
    string id;
    int a;
    int b;
    int c;
} typedef player;

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0);
    cin.tie(0);

    //---------SOLUTION----------//
    auto acomp = [](const player &a, const player &b) {
        return (a.a == b.a) ? !lexicographical_compare(a.id.begin(),a.id.end(),b.id.begin(),b.id.end()) : a.a < b.a;
    };
    auto bcomp = [](const player &a, const player &b) {
        return (a.b == b.b) ? !lexicographical_compare(a.id.begin(),a.id.end(),b.id.begin(),b.id.end()) : a.b < b.b;
    };
    auto ccomp = [](const player &a, const player &b) {
        return (a.c == b.c) ? !lexicographical_compare(a.id.begin(),a.id.end(),b.id.begin(),b.id.end()) : a.c < b.c;
    };
    auto ocomp = [](const string &a, const string &b) { return !lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()); };

    priority_queue<player, vector<player>, decltype(acomp)> skill_a(acomp);
    priority_queue<player, vector<player>, decltype(bcomp)> skill_b(bcomp);
    priority_queue<player, vector<player>, decltype(ccomp)> skill_c(ccomp);
    priority_queue<string, vector<string>, decltype(ocomp)> out(ocomp);

    unordered_map<string, bool> players;

    int n;
    cin >> n;
    
    FOR(n) {
        player p;
        string s;
        getline(cin, s) >> p.id >> p.a >> p.b >> p.c;

        skill_a.push(p);
        skill_b.push(p);
        skill_c.push(p);

        players.insert_or_assign(p.id, false);
    }
    
    const char DELIM = ' ';
    for(int i = 0; i < n/3; i++) {
        sift(skill_a);
        if(skill_a.empty()) {
            break;
        }
        out.push(skill_a.top().id);
        //out += skill_a.top().id + DELIM;
        players.insert_or_assign(skill_a.top().id, true);

        sift(skill_b);
        if(skill_b.empty()) {
            break;
        }
        out.push(skill_b.top().id);
        //out += skill_b.top().id + DELIM;
        players.insert_or_assign(skill_b.top().id, true);

        sift(skill_c);
        if(skill_c.empty()) {
            break;
        }
        out.push(skill_c.top().id);
        //out += skill_c.top().id;
        players.insert_or_assign(skill_c.top().id, true);

        cout << out.top() << DELIM;
        out.pop();
        cout << out.top() << DELIM;
        out.pop();
        cout << out.top() << endl;
        out.pop();
    }
    cout << endl;
    return 0;
}
