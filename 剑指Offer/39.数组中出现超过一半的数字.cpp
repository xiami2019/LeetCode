class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int preNum = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == preNum) {
                ++count;
            }
            else{
                --count;
            }

            if (count < 0) {
                preNum = nums[i];
                count = 1;
            }
        }
        return preNum;
    }
};