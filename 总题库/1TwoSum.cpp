class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        int numsLen = nums.size();

        for (int i = 0; i < numsLen; i++) {
            if (seen.count(target - nums[i])) {
                return vector<int>({seen[target - nums[i]], i});
            }
            else {
                seen[nums[i]] = i;
            }
        }
        return vector<int>();
    }
};