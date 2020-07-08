// BFS
class Solution {
public:
    bool isValid(string s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') ++cnt;
            else if (c == ')') {
                if (cnt < 1) return false;
                --cnt;
            }
        }
        return cnt == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        set<string> level;
        vector<string> res;
        level.insert(s);
        while (level.size()) {
            for (auto iter = level.begin(); iter != level.end(); ++iter) {
                if (isValid(*iter)) {
                    res.push_back(*iter);
                }
            }
            if (res.size() != 0) break;
            set<string>nextLevel;
            for (auto iter = level.begin(); iter != level.end(); ++iter) {
                string temp = *iter;
                for (int i = 0; i < temp.size(); ++i) {
                    if (temp[i] == '(' || temp[i] == ')') {
                        nextLevel.insert(temp.substr(0, i) + temp.substr(i + 1));
                    }
                }
            }
            level = nextLevel;
        }
        return res;
    }
};

// DFS