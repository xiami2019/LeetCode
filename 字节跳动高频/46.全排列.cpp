class Solution {
    void backtrack(vector<vector<int> >& result, vector<int>& nums, int first, int n) {
        if (first == n) {
            result.emplace_back(nums);
            return;
        }

        for (int i = first; i < n; i++) {
            swap(nums[i], nums[first]);
            first++;
            backtrack(result, nums, first, n);
            first--;
            swap(nums[i], nums[first]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        backtrack(result, nums, 0, nums.size());
        return result;
    }
};