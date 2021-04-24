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
            data[b].rep = data[a].rep;
            data[b].size += data[a].size;
        } else {
            data[a].rep = data[b].rep;
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