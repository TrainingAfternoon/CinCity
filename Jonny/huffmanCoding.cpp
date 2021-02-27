/**
 * Kind of whack Huffman Coding, but it does work
 * Creates a tree structure among connected nodes to create codes for characters that can appear in a word
 * @param s The word that you are giving
 */
void huffmanCode(string s) {
    struct node {
        char val;
        int count;
        node* left;
        node* right;
    public: node(char c, int i) {
            val = c;
            count = i;
            left = right = nullptr;
        }
    };
    map<char, int> vals;
    for (char c: s) {
        if (vals.find(c) != vals.end()) {
            vals[c]++;
        } else {
            vals[c] = 1;
        }
    }
    vector<node> nodes;
    nodes.reserve(vals.size());
    for(auto p: vals) {
        nodes.emplace_back(p.first, p.second);
    }
    auto sortRule = [] (node const& s1, node const& s2) -> bool {
        return s1.count > s2.count;
    };
    sort(nodes.begin(), nodes.end(), sortRule);
    node root = node(0, 0);
    // creating the tree
    node *curr = &root;
    for (int i = 0; i < nodes.size() - 1; ++i) {
        curr->left = &nodes[i];
        curr->right = (node *) malloc(sizeof(node));
        curr->right->val = 0;
        curr->right->count = 0;
        curr = curr->right;
    }
    curr = &nodes[nodes.size()-1];
    /*
     * OUTPUT:
     *  - prints out the code for each character
     */
    for (auto p: vals) {
        node *trace = &root;
        char c = p.first;
        cout << c << ": ";
        string res;
        while (c != trace->val && trace->right != nullptr) {
            if (trace->left->val == c) {
                res += "0";
                trace = trace->left;
            } else {
                res += "1";
                trace = trace->right;
            }
        }
        cout << res << nl;
    }
}