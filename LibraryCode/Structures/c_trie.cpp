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

void free(node *head) {
    for(int i = 0; i < sizeof((head->children))/sizeof(node*); i++) {
        if(head->children[i] != NULL) {
            free(head->children[i]);
        }
    }
    delete head;
}

