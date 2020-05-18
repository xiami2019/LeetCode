/*
方法一：DP
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int numsLen = nums.size(), maxLen = 1;
        vector<int> dptable(numsLen, 1);
        for (int i = numsLen - 2; i >= 0; i--){
            int temp = i + 1;
            while (temp < numsLen){
                if (nums[i] < nums[temp]){
                    dptable[i] = max(dptable[i], dptable[temp] + 1);
                }
                temp++;
            }
            maxLen = max(maxLen, dptable[i]);
        }
        return maxLen;
    }
};

/*
方法二：贪心+二分查找；
思路：如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，因此我们希望每次
在上升子序列最后加上的那个数尽可能的小。

维护一个数组d[i], 表示长度为i的最长上升子序列的末尾元素的最小值，用len记录目前最长上升子序列的长度，起始时len为1，d[1] = nums[0]
易证d[i]是关于i递增的。

我们依次遍历数组nums[]中的每个元素，并更新数组d[]和len的值。如果nums[i] > d[len]则更新len = len + 1；
否则在d[1,...,len]中找满足d[i-1] < nums[j] < d[i]的下标i，并更新d[i] = nums[j]。

根据d数组的单调性，我们可以使用二分查找寻找下标i，优化时间复杂度。

算法流程为：
设当前已求出的最长上升子序列的长度为len(初始为1)，从前往后遍历数组nums，在遍历到nums[i]时：
如果nums[i] > d[len], 则直接加入到d数组末尾，并更新len=len + 1；
否则，在d数组中二分查找，找到第一个比nums[i]小的数d[k]，并更新d[k + 1] = nums[i]（因为d[i]是递增的）。
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (0 == n){
            return 0;
        }
        vector<int> d(n+1);
        d[len] = nums[0];
        for (int i = 1; i < n; i++){
            if (nums[i] > d[len]){
                d[++len] = nums[i];
            }
            else{ // 进行二分查找，找到第一个比nums[i]小的数d[k]；
                // 如果找不到说明所有的数都比nums[i]大，此时要更新d[1]，将pos设为0
                int left = 1, right = len, pos = 0;
                while (left <= right){
                    int mid = (left + right) / 2;
                    if (d[mid] < nums[i]){
                        pos = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};