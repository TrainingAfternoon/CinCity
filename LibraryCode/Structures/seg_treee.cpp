//
// Created by Jonny Keane on 9/6/21.
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

template<typename E>
class segment_tree {
public:
    pair<E, E> * data;
    int size;

    segment_tree(int n) {
        size = 1;
        while (size < n) { size <<= 1; }
        data = (pair<E, E> *)malloc((2 * size) * sizeof(pair<E, E>));
        memset(data, 0, (2 * size) * sizeof(pair<E, E>));
    }

    void add(int index, int x) {
        index += size;
        data[index].first += x;
        for (index /= 2; index >= 1; index /= 2) {
            data[index].first += x;
        }
    }

    void add_range(int a, int b, int x) {
        add_range(a, b, x, 1, 0, size - 1);
    }

    void add_range(int a, int b, int x, int seg_tree_ind, int seg_tree_ind_left, int seg_tree_ind_right) {
        if (b < seg_tree_ind_left || a > seg_tree_ind_right) return; // if none of the range is encompassed, return
        if (a <= seg_tree_ind_left && seg_tree_ind_right <= b) { // if encompasses whole range, add to all in range and return
            if (seg_tree_ind < size) {
                data[seg_tree_ind].second += x;
            } else {
                data[seg_tree_ind].first += x;
            }
            return;
        }
        data[seg_tree_ind].first += (min(b, seg_tree_ind_right) - max(seg_tree_ind_left, a) + 1) * x; // add the overlapping section
        int middle = (seg_tree_ind_left + seg_tree_ind_right) / 2; // otherwise, add range first half & add range second half
        add_range(a, b, x, 2*seg_tree_ind, seg_tree_ind_left, middle);
        add_range(a, b, x,  2 * seg_tree_ind + 1, middle + 1, seg_tree_ind_right);
    }

    E sum(int a, int b) {
        return sum(a, b, 1, 0, size - 1, 0); // sum on [a, b] over the range [x, y]
    }

    E sum(int a, int b, int seg_tree_ind, int seg_tree_ind_left, int seg_tree_ind_right, int add_all) {
        if (seg_tree_ind < size) {
            data[seg_tree_ind].second += add_all;
        } else {
            data[seg_tree_ind].first += add_all;
        }
        if (b < seg_tree_ind_left || a > seg_tree_ind_right) return 0; // if none of the range is encompassed, return 0
        if (a <= seg_tree_ind_left && seg_tree_ind_right <= b) {
            return data[seg_tree_ind].first + (seg_tree_ind_right - seg_tree_ind_left + 1) * data[seg_tree_ind].second; // if whole range is encompassed, return section
        }
        int d = (seg_tree_ind_left + seg_tree_ind_right) / 2; // otherwise, return the first half sum + the second half sum
        add_all = data[seg_tree_ind].second;
        data[seg_tree_ind].first += (seg_tree_ind_right - seg_tree_ind_left + 1) * data[seg_tree_ind].second;
        data[seg_tree_ind].second = 0;
        return sum(a, b,2*seg_tree_ind, seg_tree_ind_left, d, add_all) + sum(a, b, 2 * seg_tree_ind + 1, d + 1, seg_tree_ind_right, add_all);
    }

//    E & operator [] (int index) {
//        return data[index + size].first;
//    }

    void dfs() {
        dfs(0, 1, 0, size - 1);
    }

    void dfs(int indent, int seg_tree_index, int seg_tree_left, int seg_tree_right) {
        for (int i = 0; i < indent; ++i) {
            cout << "  ";
        }
        cout << data[seg_tree_index].first << " " << data[seg_tree_index].second << " [" << seg_tree_left << ":" << seg_tree_right << "]" << endl;
        if (seg_tree_left == seg_tree_right) {
            return;
        }
        int middle = (seg_tree_left + seg_tree_right) / 2;
        dfs(indent + 1, seg_tree_index * 2, seg_tree_left, middle);
        dfs(indent + 1, seg_tree_index * 2 + 1, middle + 1, seg_tree_right);
    }
};