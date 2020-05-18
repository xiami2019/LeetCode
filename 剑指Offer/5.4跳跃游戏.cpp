class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, numsLen = nums.size(), end = 0, step = 0;
        for (int i = 0; i < numsLen - 1; i++) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    step++;
                }
            }
        }
        return step;
    }
};