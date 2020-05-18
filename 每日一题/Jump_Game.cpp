class Solution {
public:
    bool canJump(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen <= 1) return true; 
        bool dpTable[numsLen];
        dpTable[numsLen - 1] = true;
        int leastTrue = numsLen - 1;
        for (int i = numsLen - 2; i >= 0; i--) {
            int border = min(i + nums[i], numsLen - 1);
            if (border > leastTrue) {
                dpTable[i] = true;
                leastTrue = i;
            }
            else dpTable[i] = false;
        }
        return dpTable[0];
    }
};

/*
贪心
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightMost = 0;
        for (int i = 0; i < n; i++) {
            if (i <= rightMost) {
                rightMost = max(rightMost, i + nums[i]);
                if (rightMost >= n - 1) return true;
            }
            if (i > rightMost) return false;
        }
        return false;
    }
};