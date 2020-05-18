class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int i : nums) {
            ret ^= i;
        }
        int div = 1;
        while ((div & ret) == 0) {
            div <<= 1;
        }
        int a = 0, b = 0;
        for (int i : nums) {
            if (div & i) {
                a ^= i;
            }
            else {
                b ^= i;
            }
        }
        return vector<int>{a, b};
    }
};