//
// Created by Jonny Keane on 2/26/21.
//
#include <bits/stdc++.h>

#define nl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // code here
    int n;
    cin >> n;
    double total = 1.0;
    double div = 1;
    for(int i = 1; i <= n && i <= 17; ++i) {
        div *= i;
        total += 1.0/(double)div;
    }
    printf("%.13f", total);

    return 0;
}


