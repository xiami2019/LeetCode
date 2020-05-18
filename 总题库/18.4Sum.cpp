class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int numsLen = nums.size();
        vector<vector<int>> res;
        if (numsLen < 4) return res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < numsLen; i++) {
            if (nums[i] > target && nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int newTarget = target - nums[i];
            for (int j = i + 1; j < numsLen; j++) {
                if (nums[j] > newTarget && nums[j] > 0) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1, right = numsLen - 1;
                while (left < right) {
                    int tempSum = nums[j] + nums[left] + nums[right];
                    if (tempSum == newTarget) {
                        res.emplace_back(vector<int>({nums[i], nums[j], nums[left], nums[right]}));
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                    else if (tempSum < newTarget) left++;
                    else if (tempSum > newTarget) right--;
                }
            }
        }
        return res;
    }
};