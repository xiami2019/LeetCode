// 递归解法 (比较耗时，可能会超时)

class Solution {
    bool isMatchHelper(string& s, string& p, int indexS, int indexP) {
        if (indexS == s.length() && indexP == p.length()) {
            // 已经到了字符串和模版末尾，匹配成功
            return true;
        }

        if (indexS != s.length() && indexP == p.length()) {
            // 模版已经到了末尾，但字符串还未到末尾
            return false;
        }

        if (p[indexP + 1] == '*') {
            // 模版的后一个字符是'*'
            if (p[indexP] == s[indexS] || (p[indexP] == '.' && indexS < s.length())) {
                // 第一个字符已经匹配，字符串索引往后一位。
                return isMatchHelper(s, p, indexS + 1, indexP + 2) || isMatchHelper(s, p, indexS + 1, indexP) || isMatchHelper(s, p, indexS, indexP + 2);
            }
            else {
                // 没有匹配，忽略模版的*匹配
                return isMatchHelper(s, p, indexS, indexP + 2);
            }
        }
        if (s[indexS] == p[indexP] || (p[indexP] == '.' && indexS < s.length())) {
            return isMatchHelper(s, p, indexS + 1, indexP + 1);
        }
        return false;
    }

public:
    bool isMatch(string s, string p) {
        return isMatchHelper(s, p, 0, 0);
    }
};

// 回溯法
// 如果模式串中有星号，它会出现在第二个位置，即pattern[1]。这种情况下，我们可以直接忽略模式串中这一部分，或者删除匹配串的第一个字符，
// 前提是它能够匹配模式串当前位置字符，即pattern[0]。
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) return s.length() == 0;
        bool firstMatch = (s.length() != 0 && (p[0] == s[0] || p[0] == '.' ));

        if (p.length() >= 2 && p[1] == '*') {
            return (isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p)));
        }
        else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};