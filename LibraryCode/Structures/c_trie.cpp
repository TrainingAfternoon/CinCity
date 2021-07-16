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

void add_word(node *head, string& word) {
    if(head == NULL) {
        head = get_node();
    }
    if(!word.empty()) {
        if(head->children[get_key(word.front())] == NULL) {
            head->children[get_key(word.front())] = get_node_s(word.front());
        }
        head = head->children[get_key(word.front())];
        word.erase(0,1);
        return add_worse(head, word);
    }
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

