//
// Created by Jonny Keane on 8/9/21.
//

#include <bits/stdc++.h>

using namespace std;

class Arr4D {
public:
    int *dim;
    Arr4D(int a, int b, int c, int d) {
        dim = new int[4];
        dim[0] = a; dim[1] = b; dim[2] = c; dim[3] = d;
        data = (int *) malloc(a * b * c * d * sizeof(int));
    }
    int& operator() (int a, int b, int c, int d) {
        return data[a + dim[0] * (b + dim[1] * (c + dim[2] * d))];
    }
private:
    int* data;
};

Arr4D * min_table;

void init(std::vector<std::vector<int>> arr) {
    int rows = arr.size();
    int cols = arr[0].size();
    int max_row_segs = (int)floor(log2(rows));
    int max_col_segs = (int)floor(log2(cols));

    min_table = new Arr4D(rows, cols, max_row_segs + 1,  max_col_segs+ 1);
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            min_table->operator()(row, col, 0, 0) = arr[row][col];
        }
    }

    int exp = 1;
    while (1 << exp <= max(rows, cols)) {
        int new_pow = 1 << exp;
        for (int row_exp = 0; row_exp < exp; ++row_exp) {
            int row_pow = 1 << row_exp;
            for (int row = 0; row <= rows - row_pow; ++row) {
                for (int col = 0; col <= cols - new_pow; ++col) {
                    min_table->operator()(row, col, row_exp, exp) = min(min_table->operator()(row, col, row_exp, exp - 1), min_table->operator()(row, col + (new_pow >> 1), row_exp, exp - 1));
                }
            }
        }
        for (int col_exp = 0; col_exp < exp; ++col_exp) {
            int col_pow = 1 << col_exp;
            for (int row = 0; row <= rows - new_pow; ++row) {
                for (int col = 0; col <= cols - col_pow; ++col) {
                    min_table->operator()(row, col, exp, col_exp) = min(min_table->operator()(row, col, exp - 1, col_exp), min_table->operator()(row + (new_pow >> 1), col, exp - 1, col_exp));
                }
            }
        }
        // want to do 4's on 6:
        // Yes: 0, 1, 2
        // No: 3, 4, 5
        for (int row = 0; row <= rows - new_pow; ++row) {
            for (int col = 0; col <= cols - new_pow; ++col) {
                min_table->operator()(row, col, exp, exp) = min(min_table->operator()(row, col, exp - 1, exp), min_table->operator()(row + (new_pow >> 1), col, exp - 1, exp));
            }
        }
        ++exp;
    }
//    toString:
//    for (int row_exp = 0; row_exp <= max_row_segs; ++row_exp) {
//        for (int col_exp = 0; col_exp <= max_col_segs; ++col_exp) {
//            cout << (1 << row_exp) << " " << (1 << col_exp) << endl;
//            for (int row = 0; row < rows; ++row) {
//                cout << "\t";
//                for (int col = 0; col < cols; ++col) {
//                    cout << min_table->operator()(row, col, row_exp, col_exp) << " ";
//                }
//                cout << endl;
//            }
//            cout << endl;
//        }
//    }
}

int query(int a, int b, int c, int d) {
    int dif_r = b - a + 1;
    int dif_c = d - c + 1;
    int dif_r_pow = (int)floor(log2(dif_r));
    int dif_c_pow = (int)floor(log2(dif_c));
    int first_half = min(min_table->operator()(a, c, dif_r_pow, dif_c_pow), min_table->operator()(a, d + 1 - (1 << dif_c_pow), dif_r_pow, dif_c_pow));
    int second_half = min(min_table->operator()(b + 1 - (1 << dif_r_pow), c, dif_r_pow, dif_c_pow), min_table->operator()(b + 1 - (1 << dif_r_pow), d + 1 - (1 << dif_c_pow), dif_r_pow, dif_c_pow));
    int res = min(first_half, second_half);
    return res;
}

int main()
{
//    init({{1, 2}, {3, 4}});
    init({{1, 2}, {3, 4}, {6, 7}, {3, 4}, {2, 5}, {6, 3}, {8, 1}, {9, 2}});
    cout << query(0, 1, 0, 1) << endl;
    cout << query(1, 1, 0, 1) << endl;
    cout << query(0, 0, 1, 1) << endl;
    return 0;
}
