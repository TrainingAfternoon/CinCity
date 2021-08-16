//
// Created by Jonny Keane on 8/14/21.
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

//
// Created by Jonny Keane on 4/15/21.
//
#include <bits/stdc++.h>

/**
* Class to represent a node with a representative
* and a size
*/
template <typename T>
class Node {
public:
    long rep;
    long size;
    T data;

    /**
     * Constructor to initialize the Node
     * @param rep_ the representative
     * @param size_ the size of the set it's in
     * @param data_ the data stored in the Node
     */
    Node(long rep_, long size_, T data_) {
        rep = rep_;
        size = size_;
        data = data_;
    }
    /**
     * Default constructor
     */
    Node() {
        rep = 0;
        size = 0;
        data = 0;
    }
};

/**
 * Edge between two nodes
 */
class Edge {
public:
    long a;
    long b;
    bool isBidirectional;
    long weight;

    /**
     * Constructor to initialize the Edge
     * @param a_ node A
     * @param b_ node B
     * @param w_ the weight between
     * @param isBidir if this is a bidirectional connectino
     */
    Edge(long a_, long b_, long w_, bool isBidir=false) {
        a = a_;
        b = b_;
        weight = w_;
        isBidirectional = isBidir;
    }

    /**
     * Operator for less than between two edges
     * @param a
     * @param b
     * @return
     */
    friend bool operator<(const Edge& a, const Edge& b);
};

/**
 * Operator for priority queue to compare two edges and sort
 * @param a a edge
 * @param b the other edge
 * @return boolean saying which is less than the other
 */
bool operator<(const Edge& a, const Edge& b) {
    return a.weight > b.weight;
}


/**
 * Class for a UnionFind structure
 */
template <typename T>
class UnionFind {
public:
    vector<Node<T>> data;
    long size;

    /**
     * Constructor for the UnionFind
     * @param size the size of the data
     */
    explicit UnionFind(long size_) {
        size = size_;
        vector<Node<T>> temp(size);
        data = temp;
    }

    /**
     * Joins two nodes through union find
     * @param a the first node index
     * @param b the second node index
     */
    void unite(long a, long b) {
        a = find(a);
        b = find(b);
        if (data[a].size < data[b].size) {
            data[a].rep = data[b].rep;
            data[b].size += data[a].size;
        } else {
            data[b].rep = data[a].rep;
            data[a].size += data[b].size;
        }
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

    /**
     * Performs Kruskal's Algorithm to create the minimum spanning tree
     * of a graph
     * @param pq the priority queue of all of the edges in the graph
     * @param f the function to be executed for each edge added in spanning tree
     */
    void kruskals(priority_queue<Edge> pq, const function<void(Edge edge, Node<T> a, Node<T> b)>& f = nullptr) {
        int connectionsMade = 0;
        while(connectionsMade < size - 1) {
            Edge top = pq.top();
            pq.pop();
            long a = top.a, b = top.b;
            if (!same(a, b)) {
                unite(a, b);
                if (f != nullptr) {
                    f(top, data[a], data[b]);
                }
                ++connectionsMade;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int solves[4][2][2] = {{{0, 1}, {1, 0}}, {{1, 1}, {0, 1}}, {{1, 0}, {1, 1}}, {{1, -1}, {1, 0}}};
    long n;
    cin >> n;
    long dim = 1 << n;
    long goal = ((1 << (2 * n)) - 1) / 3;
    long grid[dim][dim];
    bool used[dim][dim];
    bool zero_found = false;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            cin >> grid[i][j];
            used[i][j] = false;
            if (grid[i][j] == 0) {
                if (!zero_found) {
                    zero_found = true;
                } else {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    unordered_set<long> components;
    for (long y = 0; y < dim; ++y) {
        for (long x = 0; x < dim; ++x) {
            if (used[y][x]) continue;
            used[y][x] = true;
            bool valid = false;
            for (auto & solve: solves) {
                bool does_solve = true;
                for (auto & delta: solve) {
                    long dx = delta[1] + x;
                    long dy = delta[0] + y;
                    if (dx < 0 || dx >= dim || dy < 0 || dy >= dim || grid[dy][dx] != grid[y][x]) {
                        does_solve = false;
                        break;
                    }
                    used[dy][dx] = true;
                }
                if (does_solve) {
                    valid = true;
                    break;
                }
            }
            if (valid) {
                components.insert(grid[y][x]);
            }
        }
    }
    if (components.size() == goal && zero_found) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}