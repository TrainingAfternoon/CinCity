//
// Created by Jonny Keane on 4/29/21.
// Reads generic array
//

/**
 * Reads an array of generic elements
 * Pre: The type of the elements should be capable of being input through cin calls
 * @tparam T The type of the objects in the return array
 * @param arr Pointer to the array to fill
 * @param size The size of the array
 * @return A pointer to the array of generic elements
 */
 // Code Jam gave this a runtime error
template <typename T>
T* readArray(T* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    return arr;
}
