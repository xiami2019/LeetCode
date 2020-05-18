class Solution {
    string num2str[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void combine(vector<string>& res, string cur, string digits, int start) {
        if (start == digits.length() - 1) {
            for (char c : this->num2str[digits[start] - '0' - 2]) {
                res.emplace_back(cur + c);
            }
        }
        else {
            for (char c : this->num2str[digits[start] - '0' - 2]) {
                this->combine(res, cur + c, digits, start + 1);
            }
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) return res;
        string cur = "";
        this->combine(res, cur, digits, 0);
        return res;
    }
};