/*
官方题解：https://leetcode-cn.com/problems/132-pattern/solution/132mo-shi-by-leetcode-2/
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen < 3) return 0;
        stack<int> s; // s是一个递减栈，为了满足大于i元素小于j元素的条件，且减少了找到k的时间复杂度

        vector<int> minPrefix(numsLen);
        minPrefix[0] = nums[0];
        for (int i = 1; i < numsLen; ++i) {
            minPrefix[i] = min(minPrefix[i - 1], nums[i]);
        }

        for (int i = numsLen - 1; i >= 0; --i) {
            if (nums[i] > minPrefix[i]) {
                if (s.empty()) {
                    s.push(nums[i]);
                }
                else {
                    while (s.top() < nums[i]) {
                        if (s.top() > minPrefix[i]) {
                            return true;
                        }
                        s.pop();
                    }
                    s.push(nums[i]);
                }
            }
        }
        return false;
    }
};

// [3,5,0,3,4]