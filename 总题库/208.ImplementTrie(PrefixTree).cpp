class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for (char c : word) {
            if (root->next[c - 'a'] == NULL) root->next[c - 'a'] = new Trie();
            root = root->next[c - 'a'];
        }
        root->isString = true; // 用来标记是否是单词结尾
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for (char c : word) {
            if (root->next[c - 'a'] == NULL) return false;
            root = root->next[c - 'a'];
        }
        return root->isString;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for (char c : prefix) {
            if (root->next[c - 'a'] == NULL) return false;
            root = root->next[c - 'a'];
        }
        return true;
    }

private:
    bool isString = false;
    Trie* next[26] = {NULL};
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */