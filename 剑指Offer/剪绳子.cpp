/*
动态规划法；
*/
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2) return 0;
        if (n == 2) return 1;
        if (n == 3) return 2;
       int dp[n + 1];
       for (int i = 0; i < n + 1; i++) {
           dp[i] = 0;
       }
       dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3;
       for (int i = 4; i <= n; i++) {
           for (int j = 1; j <= i / 2; j++) {
               dp[i] = max(dp[i], dp[i - j] * dp[j]);
           }
       }
       return dp[n];
    }
};

/*
贪心算法：当n≥5时，尽可能多地剪成长度为3的绳子；当剩下的绳子长度为4时，把绳子
剪成两段长度为2的绳子。
*/
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2) return 0;
        if (n == 2) return 1;
        if (n == 3) return 2;
        // 尽可能剪去长度为3的线段
        int timesOf3 = n / 3;
        // 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段
        if (n % 3 == 1) timesOf3--;
        int timesOf2 = (n - timesOf3 * 3) / 2;

        return (int)pow(3, timesOf3) * (int)pow(2, timesOf2);        
    }
};