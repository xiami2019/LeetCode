class Solution {
    vector<string> res;
    void dfs(string& s, int index) {
        if (index == s.length() - 1) {
            res.emplace_back(s);
            return;
        }
        set<char> seen;
        for (int i = index + 1; i < s.length(); i++) {
            if (seen.find(s[i]) != seen.end()){
                continue; // 重复，减枝
            }
            seen.insert(s[i]);
            swap(s[index], s[i]);
            this->dfs(s, index + 1);
            swap(s[index], s[i]);
        }
    }

public:
    vector<string> permutation(string s) {
        this->dfs(s, 0);
        return res;
    }
};