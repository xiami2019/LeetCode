class Solution {
public:
    int reverse(int x) {
        int max_int = (1<<31) - 1, min_int = 1 << 31;//位运算算出int类型的范围；
        long result = 0;
        for(; x; result = result * 10 + x % 10, x /= 10);
        return result > max_int || result < min_int ? 0 : result;
    }
};