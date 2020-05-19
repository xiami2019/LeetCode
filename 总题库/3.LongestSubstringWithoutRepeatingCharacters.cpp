class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> indexes; // 记录一个字符最后出现的位置
        int low = 0, high = 1;
        if (s.length() < 2) return s.length();

        indexes[s[0]] = 0;
        int maxLen = INT_MIN;
        int tempLen = 1;
        while (high < s.length()) {
            if (indexes.count(s[high]) == 0 || indexes[s[high]] < low) {
                indexes[s[high]] = high;
                tempLen++;
                high++;
            }
            else {
                maxLen = max(maxLen, tempLen);
                tempLen = tempLen - (indexes[s[high]] - low + 1) + 1;
                low = indexes[s[high]] + 1;
                indexes[s[high]] = high;
                high++; 
            }
        }
        maxLen = max(maxLen, tempLen);
        return maxLen;
    }
};

// 使用hashset不使用hashmap
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.length();
        // 右指针，初始值为-1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐形地表示为-1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第i到rk个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};