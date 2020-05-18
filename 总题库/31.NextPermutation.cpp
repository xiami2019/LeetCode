// 从数组末尾开始找第一个不符升序的位置，将后面的全部反序，再从当前位置往后扫描，直到
// 找到第一个大于该位置元素的元素

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen <= 1) return;

        int index = numsLen - 1;
        // 找出升序的开始的索引位置
        while (index > 0 && nums[index] <= nums[index - 1]) {
            index--;
        }
        if (0 == index) {
            // 已经是最大字典序了，直接反转数组
            int left = 0, right = numsLen - 1;
            while (left < right) swap(nums[left++], nums[right--]);
        }
        else {
            // 反转升序部分
            int left = index, right = numsLen - 1;
            while (left < right) swap(nums[left++], nums[right--]);
            // 找出第一个大于的元素
            for (int i = index; i < numsLen; i++) {
                if (nums[i] > nums[index - 1]) {
                    swap(nums[i], nums[index - 1]);
                    break;
                }
            }
        }
        return;
    }
};