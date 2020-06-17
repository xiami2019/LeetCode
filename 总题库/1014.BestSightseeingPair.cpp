// 枚举法
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int mx = A[0] + 0;
        int res = INT_MIN;
        for (int i = 1; i < A.size(); ++i) {
            res = max(res, mx + A[i] - i);
            mx = max(mx, A[i] + i);
        }
        return res;
    }
};