class Solution {
public:
    int massage(vector<int>& nums) {
        int n = (int)nums.size();
        if (!n) return 0;
        int dp0 = 0, dp1 = nums[0];

        for (int i = 1; i < n; i++){
            int tdp0 = max(dp0, dp1);
            int tdp1 = dp0 + nums[i];

            dp0 = tdp0;
            dp1 = tdp1;
        }
        return max(dp0, dp1);
    }
};