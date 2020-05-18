class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int p = 0;
        for (int i = 1; i <= n; i++) {
            ans.push_back("Push");
            if (!(p < target.size() && target[p] == i)) {
                ans.push_back("Pop");
            }
            else {
                p++;
            }
            if (p == target.size()) break;
        }
        return ans;
    }
};