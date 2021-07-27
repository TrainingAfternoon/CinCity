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
#define mp make_pair

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
#define repi(a) for(ll i=0;i<a;i++)
#define repj(a) for(ll j = 0; j < a; j++)
#define repk(a) for(ll k = 0; k < a; k++)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define in_map(m,e) (m.find(e) == m.end())
#define findchar(s,c) s.find(c)==string::npos?-1:s.find(c);

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

void fastinput(){ios_base::sync_with_stdio(0); cin.tie(0);}

// -------------------MAIN CODE-------------------//
int main(){
    int t, c, j;
    string s;
    cin>>t;
    repk(t){
        cin>>c>>j>>s;
        int sum=0, lasti= -1;
        repi(s.size()){
            if(s[i]!='?'){
                int temp = 0;
                int min = 0;
                if(lasti==-1){
                    //loop from i backwards
                    for(int ti = i-1; ti >= 0; ti--){
                        if(s[ti+1]=='J'){
                            s[ti] = 'C';
                            temp+=c;
                        } else {
                            s[ti] = 'J';
                            temp+=j;
                        }
                        if(temp < min){
                            min=temp;
                        }
                    }
                    sum+=min;
                    min = 0;
                    lasti=i;
                } 
                //forward check to next 
                do {
                    i++;
                } while(i < s.size() && s[i]=='?');
                int cur = (s[lasti]=='J')?j:c;//going to be at least one of these if different
                
                if(i!=s.size() && s[lasti] != s[i]){
                    min = cur;
                }
                //cout<<"\t"<<lasti<<endl;
                if(lasti!=i-1){
                    //cout<<"\t"<<lasti<<endl;
                    while(lasti < i && lasti < s.size()-1){
                        temp+=cur;
                        cur = ((cur==c)?j:c);
                        //cout<<"\t"<<s[lasti]<<" "<<temp<<" "<<min<<endl;
                        if(temp < min){
                            min=temp;
                        }
                        lasti++;
                    }
                } else {
                    lasti++;
                    //cout<<" adding "<<min<<nn;
                }
                    //out<<nn<<endl;
                sum+=min;
                i--;
            }
        }
        if(lasti==-1){
            //all ? chars
            int pairs = s.size()/2;
            int anti = s.size()-pairs-1;
            int min = 0;
            int temp = c<j?c:j;
            if(temp<min) min = temp;
            temp = pairs*c + anti*j;
            if(min > temp) min = temp;
            temp = pairs*j + anti*c;
            if(min > temp) min = temp;
            pairs--;
            temp = pairs*c + anti*j;
            if(min > temp) min = temp;
            temp = pairs*c + anti*j;
            if(min > temp) min = temp;
                       
            sum+=min;
        }
        cout<<"Case #"<<k+1<<": "<<sum<<endl;
    }

}
int v1(){
    fastinput();

    //---------SOLUTION----------//

    int t, x, y;
    string s;
    cin>>t;
    repk(t){
        cin>>x>>y>>s;
        int min = x<y?x:y;
        int sum = 0;
        char last = '-';
        repi(s.size()){
            if(s[i] == '?'){
                if(i!=0 && i!=s.size()-1){//if at ends, don't matter
                    //compare to the left and right. 
                    //if either are ?, then move on. copy the non-? if it
                    //exists
                    if(s[i+1]!='?'){
                        if(s[i+1]!=last && last != '-') {
                            if(last == 'C'){
                                sum+=x;
                            } else {
                                sum+=y;
                            }
                            last = s[i+1];
                            i++;
                        }
                    }
                    //else, compare the 2 options. pick lower.
                }
            } else {
                if(last != '-'){ // we've encountered other chars
                    if(last != s[i]){
                        if(last == 'C'){
                            sum+=x;
                        } else {
                            sum+=y;
                        }
                    }
                }
                last = s[i];
            }
        }
        cout<<"Case #"<<k+1<<": "<<sum<<endl;
    }
    return 0;
}

