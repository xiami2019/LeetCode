// 归并;
// 时间复杂度O(m + n), 空间复杂度O(1);

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalNums = nums1.size() + nums2.size();
        bool even = false;
        if ((totalNums & 1) == 0) {
            even = true;
        }
        int indexOfNums1 = 0, indexOfNums2 = 0, numsCount = -1, currentNum = 0, result = 0;
        int mid = (totalNums >> 1);
        while (numsCount <= mid && (indexOfNums2 < nums2.size() || indexOfNums1 < nums1.size())) {
            numsCount++;
            if (indexOfNums2 >= nums2.size() || (indexOfNums1 < nums1.size() && nums1[indexOfNums1] < nums2[indexOfNums2])) {
                currentNum = nums1[indexOfNums1];
                indexOfNums1++;
            }
            else {
                currentNum = nums2[indexOfNums2];
                indexOfNums2++;
            }
            if (even && numsCount == mid - 1) {
                result += currentNum;
            }
            if (numsCount == mid) {
                result += currentNum;
            }
        }
        return even ? result / 2.0 : result;
    }
};

// 二分查找法
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        int m = nums1.size();
        int n = nums2.size();
        
        // 分割线左边的所有元素需要满足的个数m + (n - m + 1) / 2 (这是防止整数溢出的写法)
        int totalLeft = (m + n + 1) / 2;

        // 在nums1的区间[0, m]里查找恰当的分割线
        // 使得nums1[i - 1] <= nums2[j] && nums[j - 1] <= nums[i]
        int left = 0;
        int right = m;

        // 进行二分查找
        while (left < right) {
            // 得到数组1和数组2中分割线的下标
            int i = left + (right - left + 1) / 2;
            int j = totalLeft - i;
            if (nums1[i - 1] > nums2[j]) {
                // 下一轮搜索的区间 [left, i - 1]
                right = i - 1;
            }
            else {
                // 下一轮搜索的区间 [i, right]
                left = i;
            }
        }

        int i = left;
        int j = totalLeft - i;
        // 统计中位数的候选数
        int nums1LeftMax = i == 0 ? INT_MIN : nums1[i - 1];
        int nums1RightMin = i == m ? INT_MAX : nums1[i];
        int nums2LeftMax = j == 0 ? INT_MIN : nums2[j - 1];
        int nums2RightMin = j == n ? INT_MAX : nums2[j];

        if (((m + n) % 2) == 1) {
            return max(nums1LeftMax, nums2LeftMax);
        }
        else {
            return ((max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin))) / 2.0;
        }
    }
};

