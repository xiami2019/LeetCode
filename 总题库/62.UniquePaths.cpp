// 排列组合
// 会发生溢出
class Solution {
    unsigned long factorial(int m, int n) {
        unsigned long res = 1;
        for (int i = m; i <= n; ++i) {
            res *= i;
        }
        return res;
    }

public:
    unsigned long uniquePaths(int m, int n) {
        return factorial(m - 1, m + n - 2) / factorial(1, m - 1);
    }
};

// DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};