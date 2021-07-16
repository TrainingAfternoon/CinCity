//
// Created by Jonny Keane on 7/17/21.
//

class MinSparseTable {
private:
    int* data;
    int size;
    int levels;
public:
    MinSparseTable(int size) : size(size) {
        levels = (int)floor(log2(size));
        data = (int *)malloc(size * (levels + 1) * sizeof(int));
        memset(data, 0, size * (levels + 1) * sizeof(int));
    }

    int& operator[] (int index) {
        return data[index];
    }

    void populate() {
        int delta = 1;
        for (int level = 1; level <= levels; ++level) {
            for (int i = 0; i < size - delta; ++i) {
                data[size * level + i] = min(data[size * (level - 1) + i], data[size * (level - 1) + i + delta]);
            }
            delta <<= 1;
        }
    }

    int minRange(int start, int end) {
        if (start > end) return minRange(end, start);
        int level = (int)floor(log2(end - start + 1));
        int pow = 1 << level;
        return min(data[level * size + start], data[level * size + end - pow + 1]);
    }

    string toString() {
        string res;
        for (int i = 0; i < levels + 1; ++i) {
            for (int j = 0; j < size; ++j) {
                res += to_string(data[i * size + j]) + " ";
            }
            res += "\n";
        }
        return res;
    }
};