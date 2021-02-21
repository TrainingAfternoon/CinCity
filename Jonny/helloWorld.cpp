#include <bits/stdc++.h>
#define nl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a[20];
    cout << "Size of int array: " << sizeof(a) / sizeof(int) << endl;
    std::memset(a, 0, sizeof a);
    cout << "Memset: ";
    for (int i = 0; i < 20; ++i) {
        cout << a[i] <<  " ";
    }
    cout << endl << "String Length: " << strlen("hello") << endl;

    // code here
    string s = "hi";
    cout << "Hello World!" << endl;
    cout << "String Length 2: " << s.length() << endl;
    // getchar() gives me a character from input
    cout << "a" << nl << "b" << nl;
    // template testing nl instead of endl
    return 0;
}
