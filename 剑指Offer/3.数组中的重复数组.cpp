// 使用辅助内存

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> times(nums.size());
        for (int i : nums) {
            if (times[i] != 0) {
                return i;
            }
            times[i]++;
        }
        return -1;
    }
};

// 不使用辅助内存，需要修改传入数组，将它本身作为哈希表
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                else {
                    swap(nums[i], nums[nums[i]]);
                    --i;
                }
            }
        }
        return -1;
    }
};

// 不修改数组找出重复的数字 (适用与n个数放n-1个位置的情况)
class Solution {
    int countRange(vector<int>& nums, int start, int end) {
        int res = 0;
        for (int i : nums) {
            if (i >= start && i <= end) res++;
        }
        return res;
    }

public:
    int findRepeatNumber(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen < 2) return -1;
        int start = 0, end = numsLen - 1;
        while (end >= start) {
            int middle = (end + start) >> 1;
            int count = countRange(nums, start, middle);
            if (end == start) {
                if (count > 1) {
                    return start;
                }
                else {
                    break;
                }
            }

            if (count > (middle - start + 1)) {
                end = middle;
            }
            else {
                start = middle + 1;
            }
        }
        return -1;
    }
};