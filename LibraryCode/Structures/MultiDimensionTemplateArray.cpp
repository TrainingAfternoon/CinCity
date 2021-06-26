//
// Created by Jonny Keane on 6/26/21.
//

template<typename T>
class Arr3D {
public:
    int *dim;
    Arr3D(int x, int y, int z) {
        dim = new int[3];
        dim[0] = x; dim[1] = y; dim[2] = z;
        data = (T *) malloc(x * y * z * sizeof(T));
    }
    T& operator() (int x, int y, int z) {
        return data[x + dim[0] * (y + dim[1] * z)];
    }
private:
    T* data;
};