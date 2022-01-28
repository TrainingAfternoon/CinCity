struct node{
    map<char, node*> next;
    int index;
};

node* getTrie(){
    node *n = new node();
    n->index = -1;
    return n;
}

void delTrie(node* n){
    for(auto it = n->next.begin(); it != n->next.end(); it++){
        delTrie(it->second);
    }
    delete n;
}

void addWord(node* n, string s){
    for(int i = 0; i < s.size(); i++){
        auto it = n->next.find(s[i]);
        if(it != n->next.end()){
            // we have the letter already, move on
            n = it->second;
        } else {
            node* nt = getTrie();
            n->next.emplace(s[i], nt);
            n = nt;
        }
    }
}

void listWords(node* n, string s){
    if(n->next.empty()){
        cout<<s<<" with index "<<n->index<<nn;
    } else {
        for(auto it = n->next.begin(); it != n->next.end(); it++){
            listWords(it->second, s + it->first);
        }
    }
}

// Returns the number of words
int indexWords(node* n, int i){
    if(n->next.empty()){
        n->index = i++;
    } else {
        for(auto it = t->next.begin(); it != t->next.end(); it++){
            i = indexTrie(it->second, i);
        }
    }
    return i;
}

int indexWords(node* n){
    return indexWords(n, 0);
}
