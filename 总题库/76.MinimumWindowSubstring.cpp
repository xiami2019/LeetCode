class Solution {
public:
    string minWindow(string s, string t) {
        int allChars[256] = {0};
        for (char c : t) {
            allChars[c]++;
        }
        
    }
};

S = "ADOBECODEBANC", T = "ABC"