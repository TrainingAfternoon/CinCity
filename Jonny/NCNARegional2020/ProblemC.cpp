//
// Created by Jonny Keane on 2/27/21.
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
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

using namespace std;

/**
 * Class that gives us an integer that resides within the given modulus ring
 * - we do not have a subtraction operator although trivial to implement
 *      - instead, use negative addition
 * - for division, only works if modulus is prime
 * @author Jonny Keane
 */
class PModInt {
public:
    int i;
    int mod;
    PModInt(int i_, int mod_ = 1000000007) {
        i = i_ % mod_;
        mod = mod_;
    }
    PModInt operator+ (int a) {
        i = (i + a) % mod;
        return *this;
    }
    PModInt inline operator+ (PModInt pModInt) {
        return *this + pModInt.i;
    }
    PModInt operator* (int a) {
        i = (i * a) % mod;
        return *this;
    }
    PModInt inline operator* (PModInt pModInt) {
        return *this * pModInt.i;
    }
    PModInt operator/ (PModInt pModInt) {
        int c = pModInt.modInv();
        return *this * c;
    }
    PModInt inline operator/ (int a) {
        return *this / PModInt(a, mod);
    }
    string toString() {
        return to_string(i);
    }
    int modInv() {
        return pow(mod - 2);
    }

private:
    int pow(int n) {
        if (n == 0) return 1;
        int p = pow(n / 2) % mod;
        p = (p * p) % mod;
        return (n % 2 == 0) ? p : (i * p) % mod;
    }
};

int possible(long val, int t, int bit_length) {
    int sum = 0;
    for (int i = 0; i < t; ++i) {
//        if (val - (i * (1 << (bit_length - 2))) == 0) {
//            sum++;
//        }
//        if (val - (i * (1 << (bit_length - 2))) > i * (~0L >> (64 - bit_length - 1))) {
//            sum += possible(val - (i * (1 << (bit_length - 2))), t, bit_length - 1);
//        }
//        cout << sum;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    PModInt res = PModInt(0, 998244353);
    long l;
    int t;
    cin >> l >> t;
    int bit_length = (int)(log2(l)) + 1;
//    9223372036854775807
//    3846927384799
    res = res + possible(l - (1 << (bit_length - 1)), t, bit_length);
    res = res + possible(l, t, bit_length);
    cout << res.toString();

    return 0;
}

