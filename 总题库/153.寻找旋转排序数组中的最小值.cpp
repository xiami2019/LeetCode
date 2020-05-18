class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[right] >= nums[left]) return nums[left];
            int middle = (left + right) >> 1;
            if (middle > 0 && nums[middle] < nums[middle - 1]) {
                return nums[middle];
            }
            else if (nums[middle] < nums[right]) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        return 0;
    }
};