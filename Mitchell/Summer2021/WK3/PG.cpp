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

bool comp(pair<string, double> l, pair<string, double> r){
    if(l.second < r.second) return true;
    else if (l.second > r.second) return false;
    else {
        if(l.first.size() < r.first.size()) return false;
        else if(l.first.size() > r.first.size()) return true;
        else if(l.first.compare(r.first) > 0) return true;
        return false;
    }
}
bool comp2(pair<string, int> l, pair<string, int> r){
    if(l.second < r.second) return true;
    else if (l.second > r.second) return false;
    else {
        if(l.first.size() < r.first.size()) return false;
        else if(l.first.size() > r.first.size()) return true;
        else if(l.first.compare(r.first) > 0) return true;
        return false;
    }
}
// -------------------SOLUTION--------------------//
int solve(){

    int n;
    cin>>n;
    if(n==1) {
        cout<<"1.0000";
        return 0;
    }
    string s;
    double p;
    //string p;
    double a = 0;
    //V<pair<string,double>> prob;
    //V<int> prob;
    V<double> prob;
    for(int i = 0; i < n; i++){
        cin>>s>>p;
        //int c = stoi(p.substr(2));
        //if(c==0 && p[0]=='1') c = 10000;
        //if(c!=0) prob.pb(c);
        //prob.pb(mp(s,p));
        prob.pb(p);
    }
    sort(prob.begin(), prob.end());
    //sort(prob.begin(), prob.end(), comp);
    reverse(prob.begin(), prob.end());
    for(int i = 0; i <n; i++){
        //cout<<prob[i].second<<" "<<prob[i].first<<nn;
        //a += (i+1) * prob[i].second;
        a += prob[i] * (i+1);
    }
    cout<<fixed<<setprecision(10)<<a;

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

