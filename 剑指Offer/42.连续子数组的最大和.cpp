class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubsum = INT_MIN;
        int curSum = 0;
        for (int i : nums) {
            curSum = max(curSum + i, i);
            maxSubsum = max(maxSubsum, curSum);
        }
        return maxSubsum;
    }
};