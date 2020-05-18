// 回溯法
class Solution {
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int index) {
        if (index == nums.size() - 1) {
            ans.emplace_back(nums);
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            backtrack(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};