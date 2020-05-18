class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen <= 1) return numsLen;
        int pos = 1;
        int preNumber = nums[0];
        for (int i = 1; i < numsLen; i++) {
            if (nums[i] != preNumber) {
                nums[pos++] = nums[i];
                preNumber = nums[i];
            }
        }
        return pos;
    }
};