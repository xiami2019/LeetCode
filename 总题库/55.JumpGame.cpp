class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        
        int numsLen = nums.size();
        int border = nums[0];
        int index = 0;
        while (index < nums.size() && index <= border) {
            if (nums[index] + index > border) {
                border = nums[index] + index;
                if (border >= nums.size() - 1) {
                    return true;
                }
            }
            ++index;
        }
        return false;
    }
};