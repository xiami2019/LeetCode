// 中心扩展法

class Solution {
    string checkPalindromic(string &s, int sLen, int index) {
        string subString1, subString2;
        int right = index;
        int left = index;
        while (right < sLen && left >= 0 && s[left] == s[right]) {
            left--;
            right++;
        }
        left++;
        right--;
        subString1 = s.substr(left, right - left + 1);
        if (index + 1 < sLen && s[index] == s[index + 1]) {
            right = index + 1;
            left = index;
            while (right < sLen && left >= 0 && s[left] == s[right]) {
                left--;
                right++;
            }
            left++;
            right--;
            subString2 = s.substr(left, right - left + 1);
        }
        return subString1.length() > subString2.length() ? subString1 : subString2;
    }

public:
    string longestPalindrome(string s) {
        int sLen = s.length();
        string ans = "";

        for (int i = 0; i < sLen; i++) {
            string tempStr = checkPalindromic(s, sLen, i);
            if (tempStr.length() > ans.length()) {
                ans = tempStr;
            }
        }
        return ans;
    }
};

// 中心扩展法LeetCode题解
class Solution {
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            } 
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// 动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans = "";
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i + k < n; ++i) {
                int j = i + k;
                if (k == 0) {
                    dp[i][j] = 1;
                }
                else if (k == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && k + 1 > ans.length()) {
                    ans = s.substr(i, k + 1);
                }
            }
        }
        return ans;
    }
};