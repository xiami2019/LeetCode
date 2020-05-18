class Solution {
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int middle = (left + right) >> 1;
            if (nums[middle] == target) {
                return middle;
            }
            if (nums[middle] < nums[right]) {
                // 右边是递增序列
                if (nums[middle] < target && target <= nums[right]) {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                }
            }
            else {
                // 左边是递增序列
                if (target < nums[middle] && target >= nums[left]) {
                    right = middle - 1;
                }
                else {
                    left = middle + 1;
                }
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};