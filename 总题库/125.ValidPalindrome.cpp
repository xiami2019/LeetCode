class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if (n < 2) return true;

        int low = 0, high = n - 1;
        while (low < high) {
            if (!isdigit(s[low]) && !isalpha(s[low])) {
                low++;
                continue;
            }
            if (!isdigit(s[high]) && !isalpha(s[high])) {
                high--;
                continue;
            }
            if (tolower(s[low++]) != tolower(s[high--])) return false;
        }
        return true;
    }
};