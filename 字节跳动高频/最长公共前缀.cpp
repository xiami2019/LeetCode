class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int strsLen = strs.size(), index = 0;
        if (strsLen == 0) return ans;
        while (1) {
            char currentChar = strs[0][index];
            bool flag = true;
            for (int i = 0; i < strsLen; i++) {
                if (index >= strs[i].size() || strs[i][index] != currentChar) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            ans += strs[0][index++];
        }
        return ans;
    }
};