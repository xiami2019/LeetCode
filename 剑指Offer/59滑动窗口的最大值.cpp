class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxNumberInWindow;
        deque<int> maxNumbers;
        int index = 0;
        int numsLen = nums.size();
        if (numsLen < k) return maxNumberInWindow;

        for (; index < numsLen; index++) {
            if (index >= k) {
                if (nums[index - k] == maxNumbers.front()) {
                    maxNumbers.pop_front();
                }
            }
            while (!maxNumbers.empty() && nums[index] > maxNumbers.back()) {
                maxNumbers.pop_back();
            }
            maxNumbers.push_back(nums[index]);
            if (index >= k - 1) {
                maxNumberInWindow.push_back(maxNumbers.front());
            }
        }
        return maxNumberInWindow;
    }
};