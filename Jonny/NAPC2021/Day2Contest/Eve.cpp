//
// Created by Jonny Keane on 8/10/21.
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

/**
* Class to represent a node with a representative
* and a size
*/
template <typename T>
class Node {
public:
    int rep;
    long members;
    long alive;
    int dna;

    /**
     * Default constructor
     */
    Node(int rep_) {
        rep = rep_;
        members = 1;
        alive = 1;
        dna = -1;
    }
};

/**
 * Class for a UnionFind structure
 */
template <typename T>
class UnionFind {
public:
    set<int> heads;
    vector<Node<T>> data;
    long size;

    void add(Node<T> node) {
        heads.insert(node.rep);
        data.emplace_back(node);
        ++size;
    }

    /**
     * Constructor for the UnionFind
     * @param size the size of the data
     */
    explicit UnionFind() {
        size = 0;
        data = vector<Node<T>>();
    }

    /**
     * Joins two nodes through union find
     * @param a the first node index
     * @param b the second node index
     */
    void unite(long a, long b) {
        a = find(a);
        b = find(b);
        if (data[a].members < data[b].members) {
            data[a].rep = data[b].rep;
            data[b].members += data[a].members;
            data[b].alive += data[a].alive;
            heads.erase(heads.find(a));
        } else {
            data[b].rep = data[a].rep;
            data[a].members += data[b].members;
            data[a].alive += data[b].alive;
            heads.erase(heads.find(b));
        }
    }

    void set_dna(int a, int dna_) {
        data[find(a)].dna = dna_;
    }

    /**
     * returns the ID of the representative of a node
     * @param node the node to give the representative of
     * @return the representative of the node
     */
    long find(long node) {
        while (node != data[node].rep) {
            node = data[node].rep;
        }
        return data[node].rep;
    }

    /**
     * Checks if two components are from the same set
     * @param a the first node
     * @param b the second node
     * @return if the two components are from the same set
     */
    bool same(long a, long b) {
        return find(a) == find(b);
    }

    void kill(long a) {
        --data[find(a)].alive;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    UnionFind<int> unionFind;
    int id;
    for (id = 0; id < n; ++id) {
        string sex;
        cin >> sex;
        unionFind.add(Node<int>(id));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        if (a < 0) { // death
            unionFind.kill(abs(a) - 1);
        } else { // birth
            int mother;
            cin >> mother;
            --mother;
            string sex;
            cin >> sex;
            unionFind.add(Node<int>(id++));
            if (!unionFind.same(id - 1, mother)) {
                unionFind.unite(id - 1, mother);
            }
        }
    }
    int k;
    cin >> k;
    map<int, int> dna_mappings;
    for (int i = 0; i < k; ++i) {
        int member, dna;
        cin >> member >> dna;
        unionFind.set_dna(member - 1, dna);
        if (dna_mappings.find(dna) == dna_mappings.end()) {
            dna_mappings[dna] = member - 1;
        } else {
            if (!unionFind.same(member - 1, dna_mappings[dna])) {
                unionFind.unite(member - 1, dna_mappings[dna]);
            }
        }
    }

    set<int> needed_dnas;
    int count = 0;
    for (int head: unionFind.heads) {
        if (unionFind.data[unionFind.find(head)].alive > 0) {
            ++count;
            if (unionFind.data[unionFind.find(head)].dna != -1) {
                needed_dnas.insert(unionFind.data[unionFind.find(head)].dna);
            }
        }
    }
    if (needed_dnas.size() > 1) {
        cout << "NO" << endl;
        return 0;
    }
    if (count == 1) {
        cout << "YES" << endl;
    } else {
        cout << "POSSIBLY" << endl;
    }

    return 0;
}

