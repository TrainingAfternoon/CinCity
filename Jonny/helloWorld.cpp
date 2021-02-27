//
// Created by Jonny Keane on 2/26/21.
//

#include <bits/stdc++.h>

#define nl "\n"

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // code here
    PModInt a = PModInt(11, 17);
    a = a / 5;
    cout << a.toString() << nl;

    return 0;
}



