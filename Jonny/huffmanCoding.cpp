void huffmanCode(string s) {
    struct node {
        char val;
        int count;
//        bool path;
        struct node* left;
        struct node* right;
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
        return s1.count < s2.count;
    };
    sort(nodes.begin(), nodes.end(), sortRule);
    node start = node(0, nodes[0].count + nodes[1].count);
    start.right = &nodes[0];
    start.left = &nodes[1];
    int i = 2;
    while (i < nodes.size()) {
        node temp = node(0, nodes[i].count + start.count);
        temp.left = &nodes[i];
        temp.right = &start;
        cout << temp.right->count;
        start = temp;
        ++i;
    }

//    for (auto p: vals) {
//        string res;
//        char c = p.first;
//        node *curr = &start;
//        node *find = curr -> right;
//        cout << find -> left -> val;
//        while (curr->val != c && curr->right != nullptr) {
//            if (curr->left->val == c) {
//                res += "0";
//                curr = curr->left;
//            } else {
//                res += "1";
//                curr = curr->right;
//                cout << curr -> left -> val;
//            }
//        }
//        cout << res;
//    }
}