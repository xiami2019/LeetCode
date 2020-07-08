class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if (k == 0) return res;
        int tempLen = shorter * k;
        res.push_back(tempLen);
        if (shorter == longer) return res;
        for (int i = 1; i <= k; ++i) {
            res.push_back(tempLen + i * (longer - shorter));
        }         
        return res;
    }
};