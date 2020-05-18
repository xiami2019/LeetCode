/*背包型动态规划
可以转换问题为：绳子的长度为N，剪为长度（1 <= L <= N）的子段，求每段绳子长度的最大乘积，即为完全背包问题
dp[i]表示绳子长为i的最大乘积，
则由动态转换方程dp[i] = Max{dp[i - L] * i} (1 <= L < n, L <= i <= n)

方法2：
枚举得出应该尽量拆成3和2；
*/
class Solution {
    //自底向上的动态规划；
public:
    int cuttingRope(int n) {
        int dp[n + 1] = {0};
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++){
            for (int j = 1; j < i; j++){
                dp[i] = max(dp[i], max(dp[i-j] * j, (i - j) * j));
            }
        }
        return dp[n];
    }
};

class Solution {
    //自底向上的动态规划；
public:
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int result = 1;
        while(n != 4 && n != 2 && n!= 0){
            result *= 3;
            n -= 3;
        }
        if (n != 0){
            result *= n;
        }
        return result;
    }
};




