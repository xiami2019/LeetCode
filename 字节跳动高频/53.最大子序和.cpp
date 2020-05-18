// 动态规划

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int numsLen = nums.size(), maxSubSum = nums[0]; //数组长度和结果值
        vector<int> maxSumNow(numsLen); // 动态规划表，用来保存以当前位置结尾的最大连续子数组和
        maxSumNow[0] = nums[0];

        if (numsLen == 1) return nums[0];

        for (int i = 1; i < numsLen; i++) {
            if (maxSumNow[i-1] < 0) { // 如果当前位置子数组和小于0，则对结果产生负面影响，不加上去
                maxSumNow[i] = nums[i];
            }
            else {
                maxSumNow[i] = maxSumNow[i-1] + nums[i]; // 将当前的数字加在前一个位置的最大子数组和上
            }
            maxSubSum = max(maxSubSum, maxSumNow[i]); // 维护最大连续子数组和数值；
        }

        return maxSubSum;
    }
};