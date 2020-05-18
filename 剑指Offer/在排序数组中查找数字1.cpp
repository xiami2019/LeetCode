/*
使用两次二分查找找到第一个K和最后一个K，因为数组是排序数组，相等的数一定在一起，
所以两者相减再加一即是答案。
*/

class Solution {
    int getFirstK(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;

            if (nums[mid] == target) {
                if (mid - 1 < 0 || nums[mid - 1] != target) {
                    return mid;
                }
                else {
                    right = mid - 1;
                }
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }


    int getLastK(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;

            if (nums[mid] == target) {
                if (mid + 1 >= nums.size() || nums[mid + 1] != target) {
                    return mid;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int firstK = this->getFirstK(nums, target);
        if (-1 == firstK) return 0;
        int lastK = this->getLastK(nums, target);
        return lastK - firstK + 1;
    }
};