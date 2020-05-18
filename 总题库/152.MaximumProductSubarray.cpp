// DP

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen == 1) return nums[0];
        int positive = nums[0] > 0 ? nums[0] : 0;
        int negative = nums[0] > 0 ? 0 : nums[0];
        int maxP = max(positive, negative);

        for (int i = 1; i < numsLen; i++) {
            if (nums[i] > 0) {
                positive = max(positive * nums[i], nums[i]);
                negative = negative * nums[i];
            }
            else if (nums[i] == 0) {
                positive = 0;
                negative = 0;
            }
            else {
                int oldPositive = positive;
                positive = negative * nums[i];
                negative = min(oldPositive * nums[i], nums[i]);
            }
            maxP = max(maxP, positive);
        }

        return maxP;
    }
};


// LeetCode标准解答
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};