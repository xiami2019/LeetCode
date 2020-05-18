/*
动态规划
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen == 0) return 0;
        if (numsLen == 1) return nums[0];
        int robed = nums[0], notRobed = 0;
        for (int i = 1; i < numsLen; i++) {
            int temp = robed;
            robed = max(notRobed + nums[i], robed);
            notRobed = max(temp, notRobed);
        }
        return max(robed, notRobed);
    }
};