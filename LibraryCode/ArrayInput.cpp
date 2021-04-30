//
// Created by Jonny Keane on 4/29/21.
// Reads generic array
//

template <typename T>
T* readArray(int size) {
    T* arr = new T(size);
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    return arr;
}
