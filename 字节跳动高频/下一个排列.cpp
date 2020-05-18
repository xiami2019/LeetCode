class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int numsLen = (int)nums.size();
        int down = -1;
        for (int i = numsLen - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                down = i - 1;
                break;
            }
        }
        if (down == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = down + 1; i < numsLen; i++) {
            if (i == numsLen - 1 || nums[down] >= nums[i + 1]) {
                swap(nums[down], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + down + 1, nums.end());
    }
};