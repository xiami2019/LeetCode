class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return n;
        int pre1 = 1, pre2 = 1;
        for (int i = 2; i <= n; ++i) {
            int temp = pre2;
            pre2 = pre1;
            pre1 = pre2 + temp;
        }
        return pre1;
    }
};

// 使用斐波那契数列的通项公式
class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)(fibn / sqrt5);
    }
};
