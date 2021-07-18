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
int n, m;
struct Book {
    long pages, deadline;
    double ppd;
    int late;
    int identity; 
} typedef book;

auto deadline_com = [](const book& a, const book& b) {
    //return !(a.ppd < b.ppd); //Organize by ppd
    return (a.deadline == b.deadline) ? (a.ppd < b.ppd) : (a.deadline < b.deadline);
};

auto ppd_com = [](const book& a, const book& b) {
    return !(a.ppd < b.ppd);
};

auto late_com = [](const book& a, const book& b) {
    return (a.late == b.late) ? !(a.ppd < b.ppd) : !(a.late < b.late);
};

auto page_com = [](const book&a, const book& b) {
    return (a.pages < b.pages);
};

long round_up(double d) {
    int di = (long)d;
    return (d-di > 0.0) ? ++di : di;
}

int moore(vector<book>& list, long rate) {
    int late = 0;
    long total = 0;
    book remove;
    remove.identity = -1;
    priority_queue<book, vector<book>, decltype(page_com)> pq(page_com);
    for(int i = 0; i < list.size(); i++) {
        book curr = list[i];
        total += curr.pages;
        pq.push(curr);
        while(remove.identity != curr.identity && (double)total/rate > curr.deadline) {
            remove = pq.top(); pq.pop();
            late++;
            total -= remove.pages;
        }
    }
    return late;
}

long bin_search(vector<book>& list, long lo, long hi, long best) {
    if(lo > hi) return best;

    long mid = (lo+hi)/2;
    int late = moore(list, mid);
    if(late > m) {
        return bin_search(list, mid+1, hi, best);
    } else {
        return bin_search(list, lo, mid-1, min(best,mid));
    }
}

int main(){
    fastinput();

    //---------SOLUTION----------//
    cin >> n >> m;
    
    //priority_queue<book, vector<book>, decltype(ppd_com)> backlog(ppd_com);
    //priority_queue<book, vector<book>, decltype(deadline_com)> pq(deadline_com);

    double lo = numeric_limits<double>::max();
    double hi = 0;
    vector<book> list(n);
    repi(n) {
        book b;
        cin >> b.pages;
        cin >> b.deadline;
        b.identity = i;
        b.ppd = (double)b.pages/b.deadline;
        if(b.ppd < lo) lo = b.ppd;
        if(b.ppd > hi) hi = b.ppd;

        //pq.push(b);
        list[i] = b;
    }
    sort(list.begin(), list.end(), deadline_com);
    
    long llo = ceil(lo);
    long lhi = n*ceil(hi);
    cout << bin_search(list, llo, lhi, lhi) << endl;

    return 0;
}
