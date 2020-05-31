class Solution {
    vector<string> res;
    unordered_set<string> seen;
    void backtrack(string& s, int index) {
        if (index == s.length()) {
            if (seen.find(s) == seen.end()) {
                res.emplace_back(s);
                seen.insert(s);
            }
            return;
        }
        for (int i = index; i < s.length(); ++i) {
            swap(s[index], s[i]);
            backtrack(s, index + 1);
            swap(s[index], s[i]);
        }
    }
public:
    vector<string> permutation(string s) {
        backtrack(s, 0);
        return res;
    }
};