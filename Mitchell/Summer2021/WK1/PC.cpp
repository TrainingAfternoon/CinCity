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

// This function returns value
// of a Roman symbol
int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}
 
// Returns decimal value of
// roman numaral
int romanToDecimal(string& str)
{
    // Initialize result
    int res = 0;
 
    // Traverse given input
    for (int i = 0; i < str.length(); i++)
    {
        // Getting value of symbol s[i]
        int s1 = value(str[i]);
 
        if (i + 1 < str.length())
        {
            // Getting value of symbol s[i+1]
            int s2 = value(str[i + 1]);
 
            // Comparing both values
            if (s1 >= s2)
            {
                // Value of current symbol
                // is greater or equal to
                // the next symbol
                res = res + s1;
            }
            else
            {
                // Value of current symbol is
                // less than the next symbol
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;
}

string integerToRoman(int n) {

    string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string result = "";

    for (int i = 0; i < 13; ++i)
    {
        while(n - values[i] >= 0)
        {
            result += str_romans[i];
            n -= values[i];
        }
    }

    return result;
}

// -------------------SOLUTION--------------------//
int solve(){
    int n;
    cin>>n;
    V<string> roman;
    for(int i = 1; i <= 1e9; i++){
        string t = integerToRoman(i);
        //cout<<i<<" converted to "<<t<<nn;
        roman.pb(t);
    }
    sort(roman.begin(), roman.end());
    int results[roman.size()];
    //vi results(roman.size());
    for(int i = 0; i < 1e9; i++){
        int r = romanToDecimal(roman[i]);
        results[r] = i;
    }
    for(int i : results){
        cout<<i<<", ";
    }
    while(--n){
        int t;
        cin>>t;
        cout<<results[t]+1<<nn;
    }
    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

