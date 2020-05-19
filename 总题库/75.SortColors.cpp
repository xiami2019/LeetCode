class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen < 2) return;
        int low = 0, high = numsLen - 1;
        int i = 0;
        while (i <= high) {
            if (nums[i] == 0) {
                swap(nums[i++], nums[low++]);
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[high--]);
            }
            else ++i;
        }
        return;
    }
};