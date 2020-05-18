// 使用字典树加回溯
class Trie {
    string word = "";
    vector<Trie*> nodes;
public:
    // string word = "";
    // vector<Trie*> nodes;
    Trie(): nodes(26, NULL) {}

    void insert(string word) { // 插入
        Trie* root = this;
        for (char c : word) {
            if (root->nodes[c - 'a'] == NULL) root->nodes[c - 'a'] = new Trie();
            root = root->nodes[c - 'a'];
        }
        root->word = word;
    }

    bool search(string word) { // 查找
        Trie* root = this;
        for (char c : word) {
            if (root->nodes[c - 'a'] == NULL) return false;
            root = root->nodes[c - 'a'];
        }
        return root->word == word;
    }

    Trie* getNodes(int value) {
        if (value < 0 || value > 26) return NULL;
        return nodes[value];
    }

    string getWord() {
        return word;
    }

    void setWord(const string newWord) {
        word = newWord;
    }
};


class Solution {
    vector<string> res;
    int rows;
    int cols;
    void dfs(vector<vector<char>>& board, Trie* root, int x, int y) {
        char c = board[x][y];
        // 定义递归边界
        if (c == '.' || root->getNodes(c - 'a') == NULL) return;
        root = root->getNodes(c - 'a');
        if (root->getWord() != "") {
            res.emplace_back(root->getWord()); // 找到这个单词后就将它删去
            root->setWord("");
        }

        board[x][y] = '.';
        if (x > 0) dfs(board, root, x - 1, y);
        if (y > 0) dfs(board, root, x, y - 1);
        if (x + 1 < rows) dfs(board, root, x + 1, y);
        if (y + 1 < cols) dfs(board, root, x, y + 1);
        board[x][y] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows ? board[0].size() : 0;
        if (rows == 0 || cols == 0) return res;

        // 建立Trie树
        Trie* root = new Trie();
        for (string word : words) {
            root->insert(word);
        }

        // 开始DFS
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, root, i, j);
            }
        }
        return res;
    }
};