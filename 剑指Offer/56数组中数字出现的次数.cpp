class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int excOr = 0; // 记录所有数字异或的结果；
        for (int i : nums) {
            excOr ^= i;
        }

        int div = 1; // 在所有数字的异或结果中找出为1的一位；
        while ((div & excOr) == 0) {
            div <<= 1;
        }

        int a = 0, b = 0; // a代表第div位为1的所有数的异或结果，b代表低div位为0的所有数的异或结果
        for (int i : nums) {
            if (div & i) {
                a ^= i;
            }
            else {
                b ^= i;
            }
        }
        return vector<int> {a,b};
    }
};