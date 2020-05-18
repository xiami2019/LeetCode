/*
滑动窗口法
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = INT_MIN;
        int right = -1;
        int sLen = s.length();
        if (sLen <= 0) return 0;

        unordered_set<char> seen; // 用来统计重复的字符;
        for (int i = 0; i < sLen; i++) {
            if (i - 1 >= 0) {
                seen.erase(s[i - 1]);
            }
            while (right + 1 < sLen && !seen.count(s[right + 1])) {
                seen.insert(s[right + 1]);
                right++;
            }
            maxLen = max(maxLen, right - i + 1);
        }
        return maxLen;
    }
};

/*
动态规划
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int curLength = 0;
        int maxLength = 0;

        int position[26] = {-1};

        for (int i = 0; i < s.length(); i++) {
            int prevIndex = position[str[i] - 'a'];
            if (prevIndex < 0 || i - prevIndex > curLength) {
                curLength++;
            }
            else {
                if (curLength > maxLength) {
                    maxLength = curLength;
                }
                curLength = i - prevIndex;
            }
            position[str[i] - 'a'] = i;
        }
        return maxLength;
    }
};
