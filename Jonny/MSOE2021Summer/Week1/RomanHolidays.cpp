//
// Created by Jonny Keane on 5/23/21.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
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
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

pair<int, string> romanNumerals[] = {
        {1, "I"},
        {2, "II"},
        {3, "III"},
        {4, "IV"},
        {5, "V"},
        {6, "VI"},
        {7, "VII"},
        {8, "VIII"},
        {9, "IX"},
        {10, "X"},
        {20, "XX"},
        {30, "XXX"},
        {40, "XL"},
        {50, "L"},
        {60, "LX"},
        {70, "LXX"},
        {80, "LXXX"},
        {90, "XC"},
        {100, "C"},
        {200, "CC"},
        {300, "CCC"},
        {400, "CD"},
        {500, "D"},
        {600, "DC"},
        {700, "DCC"},
        {800, "DCCC"},
        {900, "CM"},
        {1000, "M"}
};

string numerals[1000];

pair<string, int> genRomanNum(int val) {
    string res;
    int thousands = 0;
    while (val > 1000) {
        val -= 1000;
        ++thousands;
    }
    int pointer = 27;
    while (val != 0) {
        while (val < romanNumerals[pointer].first) {
            pointer--;
        }
        val -= romanNumerals[pointer].first;
        res += romanNumerals[pointer].second;
    }
    return make_pair(res, thousands);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 1000; ++i) {
        numerals[i - 1] = genRomanNum(i).first;
    }
    sort(numerals, numerals + 1000);
    for (int i = 0; i < 1000;++i) {
        cout << i + 1 << " " << numerals[i] << endl;
    }
    int MLoc = 1 + distance(numerals, find(numerals, numerals + 1000, "M"));
//    cout << MLoc << endl;
    int n;
    cin >> n;
    int nums[n];
    int min = 1000000007, max = -1000000007;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        pair<string, int> roman = genRomanNum(num);
        if (num > 1000 ||
                find(numerals, numerals + 1000, roman.first) <=
                find(numerals, numerals + 1000, "M")) {
            nums[i] = 1 + roman.second * MLoc +
                    distance(numerals, find(numerals, numerals + 1000, roman.first));
            if (nums[i] < min) {
                min = nums[i];
            }
        } else {
            nums[i] = -1 * (1 + distance(find(numerals, numerals + 1000, roman.first), numerals + 1000));
            if (nums[i] > max) { // trying to get to actual -1
                max = nums[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            cout << (nums[i] - min + 1) << endl;
        } else {
            cout << (nums[i] - max - 1) << endl;
        }
    }

    return 0;
}