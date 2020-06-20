// 递归写法
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) return s.length() == 0;
        bool firstMatch = (s.length() != 0 && (p[0] == s[0] || p[0] == '.' ));

        if (p.length() >= 2 && p[1] == '*') {
            // 避免出现匹配aaa和a*a这种情况，这中情况下由于a*组合的后面还有一个a，所以要提前丢弃a*组合；
            return (isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p)));
        }
        else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

// DP
/* 
状态转移方程：
如果第一个字符相同
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        if (pLen == 0) return sLen == 0;
        vector<vector<bool> > dpTable(sLen + 1, vector<bool>(pLen + 1, false)); // 二维dp数组，数据类型为bool型，dp[i][j]表示s的前i个字符和p的前j个字符能否匹配；
        dpTable[0][0] = true; // 两个空串自然可以匹配
        for (int i = 0; i <= sLen; ++i) {
            for (int j = 1; j <= pLen; ++j) {
                if (p[j - 1] == '*') { // 如果发现星号就需要检查字符加星号的情况；
                    dpTable[i][j] = dpTable[i][j] || dpTable[i][j - 2]; // 在每个位置都要考虑抛弃字符加星号组的情况；
                    if (i > 0 && (p[j - 2] == '.' || p[j - 2] == s[i - 1])) { // 如果匹配成功则检查上一个子串；
                        dpTable[i][j] = dpTable[i][j] || dpTable[i - 1][j];
                    }
                }
                else {
                    if (i > 0 && (p[j - 1] == '.' || p[j - 1] == s[i - 1])) { // 如果没有星号则直接检查能否匹配成功；
                        dpTable[i][j] = dpTable[i - 1][j - 1];
                    }
                }
            }
        }
        return dpTable[sLen][pLen];
    }
};