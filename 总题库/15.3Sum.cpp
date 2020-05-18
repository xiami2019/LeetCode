// 排序加双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> seen;
        vector<vector<int>> res;
        int numsLen = nums.size();
        if (numsLen < 3) return res;

        for (int i = 0; i < numsLen; i++) {
            if (nums[i] > 0) break; // 减枝
            if (i > 0 && nums[i] == nums[i - 1]) continue;// 去重
            int L = i + 1;
            int R = numsLen - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    res.emplace_back(vector<int>({nums[i], nums[L], nums[R]}));
                    while (L < R && nums[L] == nums[L + 1]) L++; // 去重；
                    while (L < R && nums[R] == nums[R - 1]) R--; // 去重；
                    L++;
                    R--;
                }
                else if (sum < 0) L++;
                else if (sum > 0) R--;
            }
        }
        return res;
    }
};