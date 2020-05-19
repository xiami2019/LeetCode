// 贪心算法
class Solution {
public:
    bool checkPalindrome(const string &s, int low, int high) {
        for (int i = low, j = high; i <= j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int sLen = s.length();
        int low = 0, high = sLen - 1;
        while (low <= high) {
            if (s[low] == s[high]) {
                ++low;
                --high;
            }
            else {
                return checkPalindrome(s, low + 1, high) || checkPalindrome(s, low, high - 1);
            }
        }
        return true;
    }
};