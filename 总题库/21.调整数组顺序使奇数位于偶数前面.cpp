class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.size() < 2) return nums;

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right && nums[left] & 1) {
                left++;
            }
            while (left < right && (nums[right] & 1) == 0) {
                right--;
            }
            swap(nums[left], nums[right]);
        }
        return nums;
    }
};