class Solution {
    double quickMul(double x, long long N) {
        double ans = 1.0;
        // 贡献的初始值为x
        double xContribute = x;
        // 在对N进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N & 1) {
                // 如果N二进制表示的最低位为1，那么需要计入贡献
                ans *= xContribute;
            }
            // 将贡献不断地平方
            xContribute *= xContribute;
            // 舍弃N二进制表示的最低位，这样我们每次只要判断最低位即可
            N >>= 1;
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        if (abs(x - 0) < 1e-8) return 0;
        long long N = n; // 最小的负数取绝对值转为正数后会越界
        return n >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};