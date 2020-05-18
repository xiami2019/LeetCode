// O(logn)级别的算法应该使用二分查找

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int middle = (right + left) / 2;
            if (nums[middle] == target) return middle;
            if (nums[middle] >= nums[left]) { // 左边有序
                if (target > nums[middle]) { // 此时target一定在右边
                    left = middle + 1;
                } 
                else {
                    if (target >= nums[left]) { // 此时target在左边
                        right = middle - 1;
                    }
                    else { // 此时target在右边
                        left = middle + 1;
                    }
                }
            }
            else { // 右边有序
                if (target < nums[middle]) { // 此时target一定在左边
                    right = middle - 1;
                }
                else {
                    if (target <= nums[right]) { //此时target一定在右边
                        left = middle + 1;
                    }
                    else { // 此时target一定在左边
                        right = middle - 1;
                    }
                }
            }
        }
        return -1;
    }
};