#include <bits/stdc++.h>
#include <string> 
#include <vector> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <algorithm> 
#include <functional> 
#include <iostream> 
#include <sstream> 
#include <cstdio> 

// var types
#define ll long long
#define ld long double
#define nn '\n'
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
#define repi(a) for(ll i=0;i<a;i++)
#define repj(a) for(ll j = 0; j < a; j++)
#define repk(a) for(ll k = 0; k < a; k++)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define in_map(m,e) (m.find(e) == m.end())
#define findchar(s,c) s.find(c)==string::npos?-1:s.find(c);

using namespace std;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// functs
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;} 
// trim from start (in place)
static inline void ltrim(std::string &s) {s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {return !std::isspace(ch);}));}
// trim from end (in place)
static inline void rtrim(std::string &s) {s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {return !std::isspace(ch);}).base(), s.end());}
// trim from both ends (in place)
static inline void trim(std::string &s) {ltrim(s);rtrim(s);}

void fastinput(){ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);}

// -------------------MAIN CODE-------------------//
// https://speedyguy17.info/icpc/data/rmrc/2014/talk.pdf
int get_key(char c) {
    short offset = (c <= 90) ? 65 : 71;
    return c - offset;
}

//-------[Trie]---------
struct Node {
    char symbol;
    struct Node *children[52];
    short duplicate_weight;
    bool is_word;
} typedef node;

node *get_node_s(char s) {
    node *n = new node;
    n->symbol = s;
    n->is_word = false;
    n->duplicate_weight = 1;
    return n;
}

node *get_node() {
    return get_node_s('\0');
}

short add_word(node *head, string& word) {
    //cout << word << endl;
    if(head == NULL) {
        head = get_node();
    }
    if(!word.empty()) {
        if(head->children[get_key(word.front())] == NULL) {
            head->children[get_key(word.front())] = get_node_s(word.front());
        }
        head = head->children[get_key(word.front())];
        word.erase(0, 1);
    }
        /*return add_word(head, word);
    } else {
        int ret = (head->is_word) ? (head->duplicate_weight > 0) ? head->duplicate_weight-- : 0 : 0;
        head->is_word = true;
        return ret;
    }*/
    if(word.empty()) { //Slightly less recursion required this way
        short ret = (head->is_word) ? (head->duplicate_weight > 0) ? head->duplicate_weight-- : 0 : 0;
        head->is_word = true;
        return ret;
    } else {
        return add_word(head, word);
    }
}

void free(node *head) {
    for(int i = 0; i < sizeof((head->children))/sizeof(node*); i++) {
        if(head->children[i] != NULL) {
            free(head->children[i]);
        }
    }
    delete head;
}

//-----------[Compacted Trie]---------------
const int MAX_LENGTH = 4;
struct CompactedNode {
    string symbol;
    bool is_word;
    short duplicate_weight;
    struct CompactedNode *children[52];
} typedef compacted_node;

compacted_node *get_compacted_node(string s) {
    compacted_node *node;
    node->symbol = s;
    node->is_word = false;
    node->duplicate_weight = 1;
    return node;
}

compacted_node *get_compacted_head() {
    return get_compacted_node("");
}

int add_word_compacted(compacted_node *head, string& word) {
    if(head == NULL) {
        head = get_compacted_head();
    }
   return -1; 
}
//-------------------------------------------------------------

int find_duplicates(string line) {
    node *trie = get_node();
    int substrings = 0;
    string substring;
    for(int i = 0; i < line.length(); i++) {
        for(int j = i + 1; j <= line.length(); j++) {
            /*if(j-i > line.length()/2 + 1) {
                break;
            }*/
            substring = line.substr(i, j-i);
            substrings += add_word(trie, substring);
        }
    }
    //TODO: disable for final submission
    free(trie);
    return substrings;
}

int main(){
    fastinput();

    //---------SOLUTION----------//
    int n;
    cin >> n;
    
    string line;
    repi(n) {
        cin >> line;
        cout << find_duplicates(line) << endl;
    }
    return 0;
}
