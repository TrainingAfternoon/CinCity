#include <bits/stdc++.h>

// var types
#define ll long long
#define ld long double
#define nn '\n'
#define pb push_back
#define mp make_pair

// collection shorthand
#define V vector
#define vi V<int>
#define vii V<vi>
#define vll V<ll> 
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>

// funcs 
#define inRange(x,y,l,w) (x >= 0 && x < l && y >= 0 && y < w)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define in_map(m,e) (m.find(e) == m.end())
#define findchar(s,c) s.find(c)==string::npos?-1:s.find(c);

using namespace std;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

// -------------------STRUCTS---------------------//
struct FenwickTree{
    vector<int> arr;
    int n;

    FenwickTree(int size){
        n = size;
        arr.assign(size,0);
    }

    int sum(int k){
        int s = 0;
        int ik = k+1;
        while(ik>=1){
            s+=arr[ik-1];
            ik-= ik & -ik;
        }
        return s;
    }

    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }

    void update(int k, int x){
        int ik = k+1;
        while(ik <= n){
            arr[ik-1]+=x;
            ik+= ik & -ik;
        }
    }
};

struct trie{
    map<char, trie*> to;
    int index;
};

trie* getTrie(){
    trie *t = new trie();
    t->index = -1;
    return t;
}

void delTrie(trie* t){
    for(auto it = t->to.begin(); it != t->to.end(); it++){
        delTrie(it->second);
    }
    delete t;
}

void addWord(trie* t, string s){
    for(int i = 0; i < s.size(); i++){
        auto it = t->to.find(s[i]);
        if(it != t->to.end()){
            // we have the letter already, move on
            t = it->second;
        } else {
            trie* nt = getTrie();
            t->to.emplace(s[i], nt);
            t = nt;
        }
    }
}

void listWords(trie* t, string s){
    if(t->to.empty()){
        cout<<s<<" with index "<<t->index<<nn;
    } else {
        for(auto it = t->to.begin(); it != t->to.end(); it++){
            listWords(it->second, s + it->first);
        }
    }
}

int indexTrie(trie* t, int i){
    if(t->to.empty()){
        t->index = i++;
    } else {
        for(auto it = t->to.begin(); it != t->to.end(); it++){
            i = indexTrie(it->second, i);
        }
    }
    return i;
}

// -------------------FUNCTIONS-------------------//


// -------------------SOLUTION--------------------//
int solve(){
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    FenwickTree prefix(n);
    trie* root = getTrie();
    string target;

    for(int i = 0; i < n; i++){
        cin>>target;
        addWord(root, target);
        prefix.update(i, 1);
    }
    cin>>target;

    ll vals[k];
    vals[k-1] = 1;
    for(int i = k-2; i >= 0; i--){
        vals[i] = (n-i-1) * vals[i+1];
        vals[i] %= MOD;
    }
//    for(int i = 0; i < k; i++) cout<<vals[i]<<nn;
//    cout<<nn<<"chars"<<nn;
//    for(auto it = root->to.begin(); it != root->to.end(); it++){
//        cout<<it->first<<nn;
//    }
//    cout<<"end"<<nn<<nn;

    indexTrie(root, 0);
    //listWords(root,"");

    ll count = 1;
    //for(int i = 0; i < n; i++) cout<<prefix.sum(i)<<nn;
    trie* cur = root;
    int i = 0;
    for(int j = 0; j < k; j++){
        while(!cur->to.empty()){
            cur = cur->to[target[i++]];
        }
        int prev = prefix.sum(cur->index)-1;
        //cout<<"prev "<<prev<<nn;
        count += prev * vals[j];
        count %= MOD;
        prefix.update(cur->index, -1);
        cur = root;
    }
    cout<<count;

    delTrie(root);

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

