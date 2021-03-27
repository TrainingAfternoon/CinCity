//
// Created by Jonny Keane on 3/19/21.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // input
    int rows, columns;
    cin >> rows >> columns;
    string grid[rows];
    for (int i = 0; i < rows; ++i) {
        cin >> grid[i];
    }
    // populates every element as its own set to start
    pair<int, int> links[rows][columns];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            links[i][j] = make_pair(i, j);
        }
    }

    // I start a search to populate the links one time in a dynamic array, which traverses down to get all connections points
    // It then skips future iterations that have already been mapped out
    queue<pair<int, int>> edges;
    for (int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j){
            if (make_pair(i, j) != links[i][j]) continue;
            edges.push(make_pair(i, j));
            while (!edges.empty()) {
                auto front = edges.front();
                edges.pop();
                if (front.first < rows - 1 && grid[front.first + 1][front.second] == grid[front.first][front.second] &&
                    links[front.first + 1][front.second] != links[front.first][front.second]) {
                    edges.push(make_pair(front.first + 1, front.second));
                    links[front.first + 1][front.second] = links[front.first][front.second];
                }
                if (front.second < columns - 1 && grid[front.first][front.second + 1] == grid[front.first][front.second] &&
                    links[front.first][front.second + 1] != links[front.first][front.second]) {
                    edges.push(make_pair(front.first, front.second + 1));
                    links[front.first][front.second + 1] = links[front.first][front.second];
                }
                if (front.first > 0 && grid[front.first - 1][front.second] == grid[front.first][front.second] &&
                    links[front.first - 1][front.second] != links[front.first][front.second]) {
                    edges.push(make_pair(front.first - 1, front.second));
                    links[front.first - 1][front.second] = links[front.first][front.second];
                }
                if (front.second > 0 && grid[front.first][front.second - 1] == grid[front.first][front.second] &&
                    links[front.first][front.second - 1] != links[front.first][front.second]) {
                    edges.push(make_pair(front.first, front.second - 1));
                    links[front.first][front.second - 1] = links[front.first][front.second];
                }
            }
        }
    }

    // To conclude, I just have to check that the links match each other because they should be in the same
    // "set" (having the same ID in the links array)
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (links[r1 - 1][c1 - 1] == links[r2 - 1][c2 - 1]) {
            string res = grid[r1 - 1][c1 - 1] == '1' ? "decimal" : "binary";
            cout << res << nl;
        } else {
            cout << "neither" << nl;
        }
    }
    return 0;
}
