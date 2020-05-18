/*
使用滑动窗口法解决

使用两个指针表示字符串中的某个子串（的左右边界）。其中左指针代表着上文中枚举子串的起始位置，
右指针代表上文中枚举子串的结束位置。

在每一步的操作中，我们会将左指针向右移动一格，表示 我们开始枚举下一个字符作为起始位置，然后
我们可以不断地向右移动右指针，但需要保证这两个指针对应的子串中没有重复的字符。在移动结束后，
这个子串就对应着 以左指针开始的，不包含重复字符的最长子串。我们记录下这个子串的长度

在枚举结束后，我们找到的最长的子串的长度即为答案。

使用哈希表来判重:
C++中的std::unordered_set
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet; // 用来判定字符是否重复；
        int n = s.size();
        // 右指针，初始值为-1，相当于在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐形地表示为-1
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                charSet.erase(s[i - 1]);
            }
            while (rk + 1 < n && !charSet.count(s[rk + 1])) {
                // 不断移动右指针，因为右边界是一直递增的
                charSet.insert(s[rk + 1]);
                rk++;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};