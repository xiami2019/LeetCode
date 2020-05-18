/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

/*
先使用二分查找找到峰值
*/

class Solution {
    int binarySearch(MountainArray &mountainArr, int target, int left, int right, int key(int)) {
        target = key(target);
        while (left <= right) {
            int middle = (left + right) >> 1;
            int cur = key(mountainArr.get(middle));
            if (cur == target) return middle;
            else if (cur < target) left = middle + 1;
            else right = middle - 1;
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length() - 1; 
        // 使用二分查找找到峰值
        while (left < right) {
            int middle = (left + right) >> 1;
            if (mountainArr.get(middle) < mountainArr.get(middle + 1)) left = middle + 1;
            else right = middle;
        }

        int peak = left;
        int index = binarySearch(mountainArr, target, 0, peak, [](int x) -> int{return x;});
        if (index != -1) {
            return index;
        }
        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, [](int x) -> int{return -x;});
    }
};