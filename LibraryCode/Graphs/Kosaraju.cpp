#include <bits/stdc++.h>

using namespace std;

void dfs1(int curr, const vector<vector<int>> & conns, vector<bool> & visited, vector<int> & order) {
    visited[curr] = true;
    for (int conn: conns[curr]) {
        if (!visited[conn]) {
            dfs1(conn, conns, visited, order);
        }
    }
    order.push_back(curr);
}

void dfs2(int curr, const vector<vector<int>> & conns, vector<int> & comp, int curr_comp) {
    comp[curr] = curr_comp;
    for (int conn: conns[curr]) {
        if (comp[conn] == -1) {
            dfs2(conn, conns, comp, curr_comp);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> conns(n);
    vector<vector<int>> rev_conns(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        conns[a].push_back(b);
        rev_conns[b].push_back(a);
    }

    vector<bool> visited(n, false);
    vector<int> order;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i, conns, visited, order);
        }
    }
    vector<int> comp(n, -1);
    int curr_comp = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (comp[order[i]] == -1) {
            dfs2(order[i], rev_conns, comp, curr_comp);
            ++curr_comp;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ": " << comp[i] << endl;
    }
    assert(comp[0] == 1);
    assert(comp[1] == 1);
    assert(comp[2] == 0);
    assert(comp[3] == 3);
    assert(comp[4] == 2);
    assert(comp[5] == 0);
    assert(comp[6] == 0);
}

/*
7 10
1 2
2 1
3 2
3 7
7 6
6 3
6 5
2 5
5 4
1 4

 */