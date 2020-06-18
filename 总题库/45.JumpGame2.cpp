// Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int numsLen = nums.size();
        int border = nums[0], index = 0;
        int stepCounts = 0;
        while (index < numsLen && index <= border) {
            int longest = 0;
            for (int i = index + 1; i <= border; ++i) {
                longest = max(longest, i + nums[i]);
            }
            if (longest > border) {
                border = longest;
                index = border;
                ++stepCounts;
            }
            if (border >= numsLen - 1) return stepCounts;
        }
        return 0;
    }
};