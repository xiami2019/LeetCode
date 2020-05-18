/*
方法一：存储后缀
*/

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> good(words.begin(), words.end());
        for (const string& word : words){
            for (int k = 1; k < word.size(); k++){
                good.erase(word.substr(k));
            }
        }
        int ans = 0;
        for (const string& word: good){
            ans += word.size() + 1;
        }
        return ans;
    }
};

/*
方法二：字典树
*/
class TrieNode{
    TrieNode* children[26];
public:
    int count;
    TrieNode(){
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        count = 0;
    }

    TrieNode* get(char c){
        if (children[c - 'a'] == NULL){
            children[c - 'a'] = new TrieNode();
            count++;
        }
        return children[c - 'a'];
    }
};

class Solution{
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* trie = new TrieNode();
        unordered_map<TrieNode*, int> nodes;

        for (int i = 0; i < words.size(); i++){
            string word = words[i];
            TrieNode * cur = trie;
            for (int j = word.length() - 1; j >= 0; j--){
                cur = cur->get(word[j]);
            }
            nodes[cur] = i;
        }

        int ans = 0;
        for (auto& [node, idx] : nodes){
            if (node->count == 0){ //说明是叶子节点
                ans += words[idx].length() + 1;
            }
        }
        return ans;
    }
};