// 记忆化搜索
class Solution {
    bool wordBreak(string s, unordered_set<string>& words, int start, vector<int>& memo) {
        if (start == s.length()) return true;
        if (memo[start] != 0) {
            if (memo[start] == 1) return true;
            else return false;
        }
        for (int end = start + 1; end < s.length() + 1; ++end) {
            if (words.count(s.substr(start, end - start)) && wordBreak(s, words, end, memo)) {
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = 2;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        vector<int> memo(s.length(), 0);
        for (string s : wordDict) {
            words.insert(s);
        }
        return wordBreak(s, words, 0, memo);
    }
};

// BFS
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        vector<int> memo(s.length(), 0);
        for (string s : wordDict) {
            words.insert(s);
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            if (memo[start] == 0) {
                for (int end = start + 1; end < s.length(); ++end) {
                    if (words.count(s.substr(start, end - start))) {
                        q.push(end);
                        if (end == s.length()) return true;
                    }
                }
                memo[start] = 1;
            }
        }
        return false;
    }
};

// DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
    }
}