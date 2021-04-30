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

void huffmanCode(string s) {
    struct node {
        char val;
        int count;
        node* left;
        node* right;
    public: node(char c, int i) {
            val = c;
            count = i;
            left = right = nullptr;
        }
    };
    map<char, int> vals;
    for (char c: s) {
        if (vals.find(c) != vals.end()) {
            vals[c]++;
        } else {
            vals[c] = 1;
        }
    }
    vector<node> nodes;
    nodes.reserve(vals.size());
    for(auto p: vals) {
        nodes.emplace_back(p.first, p.second);
    }
    auto sortRule = [] (node const& s1, node const& s2) -> bool {
        return s1.count > s2.count;
    };
    sort(nodes.begin(), nodes.end(), sortRule);
    node root = node(0, 0);
    // creating the tree
    node *curr = &root;
    for (int i = 0; i < nodes.size() - 1; ++i) {
        curr->left = &nodes[i];
        curr->right = (node *) malloc(sizeof(node));
        curr->right->val = 0;
        curr->right->count = 0;
        curr = curr->right;
    }
    curr = &nodes[nodes.size()-1];
    for (auto p: vals) {
        node *trace = &root;
        char c = p.first;
        cout << c << ": ";
        string res;
        while (c != trace->val && trace->right != nullptr) {
            if (trace->left->val == c) {
                res += "0";
                trace = trace->left;
            } else {
                res += "1";
                trace = trace->right;
            }
        }
        cout << res << nl;
    }
}

template <typename T>
T* readArray(int size) {
    T* arr = new T(size);
    for (int i = 0; i< size; ++i) {
        cin >> arr[i];
    }
    return arr;
}

template <typename T>
string join(vector<T> vector, const string& delimiter = ", ", const string& pre = "", const string& post = "") {
    string result = pre;
    for (int i = 0; i < vector.size() - 1; ++i) {
        result += to_string(vector[i]);
        result += delimiter;
    }
    result += to_string(vector[vector.size() - 1]);
    return result + post;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

//    // code here
//    PModInt a = PModInt(11, 17);
//    a = a / 5;
//    cout << a.toString() << nl;
//
//    huffmanCode("hellos");
//    vector<int> v;
//    cout << v.size();
//    char* arr = readArray<char>(3);
//    for (int i = 0; i < 3; ++i) {
//        cout << arr[i] << " ";
//    }
    vector<int> v = {1, 2, 3, 4};
    cout << join(v, ", ", "[", "]");
    return 0;
}



