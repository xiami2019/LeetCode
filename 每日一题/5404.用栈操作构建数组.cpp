class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int index = 0, targetLen = target.size();
        vector<string> res;
        if (targetLen == 0) return res;
        for (int i = 1; i <= n && index < targetLen; i++) {
            if (i == target[index]) {
                res.emplace_back("Push");
                index++;
            }
            else if (i < target[index]) {
                res.emplace_back("Push");
                res.emplace_back("Pop");
            }
        }
        return res;
    }
};