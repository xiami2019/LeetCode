class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen == 0) return 0;
        if (numsLen == 1) return nums[0];

        int bitSum[32] = {0};
        for (int i = 0; i < numsLen; i++) {
            long bitMask = 1;
            for (int j = 31; j >= 0; j--) {
                int bit = nums[i] & bitMask;
                if (0 != bit) {
                    bitSum[j] += 1;
                }
                bitMask <<= 1;
            }
        }

        int result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result += bitSum[i] % 3;
        }

        return result;
    }
};