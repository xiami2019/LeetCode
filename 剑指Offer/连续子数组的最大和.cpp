/*
法一：动态规划法Kadane算法；
动态规划的是首先对数组进行遍历，当前最大连续子序列和为sum，结果为ans
如果sum > 0, 则说明sum对结果有增益效果，则sum保留并加上当前遍历数字
如果sum <= 0, 则说明sum对结果无增益效果，需要舍弃，则sum直接更新为当
前遍历数字
每次比较sum和ans的大小，将最大值置为ans，遍历结束时返回结果
时间复杂度：O(n)；
空间复杂度：O(1)：
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for (int num : nums){
            if (sum > 0){ //如果前面的元素已经不能带来正增益了，就需要开始一段新的子序列；
                sum += num;
            }
            else{
                sum = num;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

/*
法二：贪心
使用单个数组作为输入来查找最大（或最小）元素（或总和）的问题，贪心算法是可以
在线性时间解决的方法之一。
每一步都选择最佳方案，到最后就是全局最优的方案。
算法：
遍历数组并在每个步骤中更新：
当前元素；
当前元素位置的最大和；
迄今为止的最大和；
时间复杂度：O(N)，只遍历一次数组。
空间复杂度：O(1)，只使用了常数空间。

实际上方法一动态规划是同一种方法。。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currSum = nums[0], maxSum = nums[0];

        for (int i = 1; i < n; i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

/*
法三：分治法；
分治法解决问题的模板：
定义基本情况；
将问题分解为子问题并递归地解决它们；
合并子问题的解以获得原始问题的解；

若n==1，返回此元素。
left_sum为最大子数组前n/2个元素，在索引为(left+right) / 2的元素属于左子数组；
right_sum为最大数组的右子数组，为最后n / 2的元素。
cross_sum是包含左右子数组且含索引（left + right）/ 2的最大值。
*/
class Solution {
public:
    struct Status{
        int leftSum, rightSum, maxSum, totalSum;
    };

    Status pushUp(Status left, Status right) {
        int totalSum = left.totalSum + right.totalSum;
        int leftSum = max(left.leftSum, left.totalSum + right.leftSum);
        int rightSum = max(right.rightSum, right.totalSum + left.rightSum);
        int maxSum = max(max(left.maxSum, right.maxSum), left.rightSum + right.leftSum);
        return (Status) {leftSum, rightSum, maxSum, totalSum};
    }

    Status get(vector<int>& nums, int left, int right) {
        if (left == right) return (Status) {nums[left], nums[left], nums[left], nums[left]};
        int middle = (left + right) >> 1;
        Status leftSub = this->get(nums, left, middle);
        Status rightSub = this->get(nums, middle + 1, right);
        return this->pushUp(leftSub, rightSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).maxSum;
    }
};