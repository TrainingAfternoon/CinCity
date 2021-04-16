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

int numDigits(int num) {
    return log10(num)+1;
}

int generateNext(int before, int current) {
    /*Alright: here's what we're doing
     *If current is less than before by a factor of ten or more, multiply by ten
     *If current is less but the same factor of ten, check if % 10 * factor == 0
     *  if yes --> += before % current + 1
     *  if no --> *10 + 1
     *if current is the same --> *10
     */
    if(before > current) {
        if(numDigits(before) == numDigits(current)) {
            if(current % (int)pow(10, log(current)) == 0) {
                return (before % current) + 1;
            } else {
                return (current*10); //I had a plus one here, why?
            }
        } else {
            return generateNext(before, current*10);
        }

    }
    if(before == current) {
        return (current*10);
    }
    return current; //before < current
}

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0);
    cin.tie(0);

    //---------SOLUTION----------//
    int cases;
    int elements;
    int element;
    int appends;

    int origDig;
    int newDig;
    int before;
    int current;
    int newCurrent;
    V<int> nums;

    cin >> cases;
    for(int i = 0; i < cases; i++) {
        appends = 0;
        cin >> elements;
        for(int j = 0; j < elements; j++) {
            cin >> element;
            nums.pb(element);
        }
        
        if(nums.size() > 1) {
            V<int>::iterator it = nums.begin();
            before = *(it++);
            current = *it;
            while(it != nums.end()) {
                origDig = numDigits(current);
                newCurrent = generateNext(before,current);
                //cout << "new current: " << newCurrent << endl;
                appends += numDigits(newCurrent) - origDig;

                before = newCurrent;
                current = *(++it);
            }
        }
        
        cout << "Case #" << (i+1) << ": " << appends << endl;
        nums.clear();
    } 


    return 0;
}
