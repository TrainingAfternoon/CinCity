//
// Created by Jonny Keane on 4/29/21.
//

/**
 * Joins a vector and returns the string of all of its pieces joined with a delimiter and post
 * Pre: The type of the objects should have a to_string(T) method defined (already done for primitives)
 * @tparam T The type of the objects in the vector
 * @param v The vector of values
 * @param delimiter The delimiter of the values in the final result
 * @param pre The string to come before everything
 * @param post The string to come after everything
 * @return The joined string
 */
template <typename T>
string join(vector<T> v, const string& delimiter = ", ", const string& pre = "", const string& post = "") {
    string result = pre;
    for (int i = 0; i < v.size() - 1; ++i) {
        result += to_string(v[i]);
        result += delimiter;
    }
    result += to_string(v[v.size() - 1]);
    return result + post;
}

