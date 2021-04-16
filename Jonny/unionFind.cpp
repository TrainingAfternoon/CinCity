//
// Created by Jonny Keane on 4/15/21.
//
#include <bits/stdc++.h>

/**
 * Class for a UnionFind structure
 */
class UnionFind {
public:
    /**
     * Class to represent a node with a representative
     * and a size
     */
    class Node {
    public:
        long rep;
        long size;

        Node(long rep_, long size_) {
            rep = rep_;
            size = size_;
        }
    };

    Node *data;

    /**
     * Constructor for the UnionFind
     * @param size the size of the data
     */
    UnionFind(int size) {
        data = new Node [size];
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
    long find(int node) {
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
     * Connection between two nodes
     */
    class Connection {
    public:
        long a;
        long b;
        bool isBidirectional;
        long weight;

        /**
         * Constructor to initialize the Connection
         * @param a_ node A
         * @param b_ node B
         * @param w_ the weight between
         * @param isBidir if this is a bidirectional connectino
         */
        Connection(long a_, long b_, long w_, bool isBidir) {
            a = a_;
            b = b_;
            weight = w_;
            isBidirectional = isBidir;
        }

        /**
         * Constructor to initialize the Connection between (default one way)
         * @param a_ node A
         * @param b_ node B
         * @param w_ the weight between
         */
        Connection(long a_, long b_, long w_) {
            this(a_, b_ w_, false);
        }

        /**
         * Operator for less than between two connections
         * @param a
         * @param b
         * @return
         */
        friend bool operator<(const Connection& a, const Connection& b);
    };

    /**
     * Operator for priority queue to compare two connections and sort
     * @param a a connection
     * @param b the other connection
     * @return boolean saying which is less than the other
     */
    bool operator<(const Connection& a, const Connection& b) {
        return a.weight > b.weight;
    }

    /**
     * Performs Kruskal's Algorithm to create the minimum spanning tree
     * of a graph
     * @param pq the priority queue of all of the connections in the graph
     */
    void kruskals(priority_queue<Connection> pq) {
        int connectionsMade = 0;
        while(connectionsMade < size - 1) {
            Connection top = pq.top();
            pq.pop();
            long a = top.a, b = top.b;
            if (!same(a, b)) {
                unite(a, b);
                ++connectionsMade;
            }
        }
    }
};
