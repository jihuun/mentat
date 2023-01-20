class trie_node {
public:
    trie_node *next[26];  
    bool is_end;

    trie_node() {
        memset(next, 0, sizeof(next));
        is_end = false;
    }
};

class Trie {
public:
    trie_node *root;
    Trie() {
        root = new trie_node;
    }
    
    void insert(string word) {
        trie_node *cur = root;
        for (int i = 0; i < word.size(); i++) {
            if (cur->next[word[i] - 'a'] == NULL) {
                cur->next[word[i] - 'a'] = new trie_node;
            }
            cur = cur->next[word[i] - 'a'];
        }
        cur->is_end = true;
    }
    
    bool search(string word) {
        trie_node *tgt = find(word);
        if (tgt && tgt->is_end == true)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        if (find(prefix))
            return true;
        return false;
        
    }
    trie_node *find(string s) {
        trie_node *cur = root;
        for (int i = 0; i < s.size() && cur; i++) {
            cur = cur->next[s[i] - 'a'];
        }
        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */