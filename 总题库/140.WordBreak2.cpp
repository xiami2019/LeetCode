// 记忆化回溯
class Solution {
    unordered_map<int, vector<string>> memo;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (string str : wordDict) {
            words.insert(str);
        }
        return wordBreak(s, wordDict, words, 0);
    }

    vector<string> wordBreak(string s, unordered_set<string>& words, int start) {
        if (memo.count(start)) {
            return memo[start];
        }
        vector<string> res;
        if (start == s.length()) {
            res.push_back("");
        }
        for (int end = start + 1; end < s.length() + 1; ++end) {
            if (words.count(s.substr(start, end - start))) {
                vector<string> temp = wordBreak(s, words, end);
                for (string s : temp) {
                    res.push_back(s.substr(start, end - start) + s == "" ? "" : " " + s);
                }
            }
        }
        memo[start] = res;
        return res;
    }
};

// DP
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (string str : wordDict) {
            words.insert(str);
        }

        vector<vector<string>> dp(s.length() + 1, vector<string>({}));
        dp[0].push_back("");

        for (int i = 1; i < s.length() + 1; ++i) {
            vector<string> temp;
            for (int j = 0; j < i; ++j) {
                if (dp[j].size() > 0 && words.count(s.substr(j, i - j + 1))) {
                    for (string str : dp[j]) {
                        temp.push_back(str + (str == "" ? "" : " ") + s.substr(j, i - j + 1));
                    }
                }
            }
            dp[i] = temp;
        }
        return dp[s.length()];
    }
};