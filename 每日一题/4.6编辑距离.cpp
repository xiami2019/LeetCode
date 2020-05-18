class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(); // word1的长度
        int m = word2.length(); // word2的长度

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // DP表
        int Dp[n+1][m+1];

        //边界状态初始化
        for (int i = 0; i < n + 1; i++) {
            Dp[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            Dp[0][j] = j;
        }

        // 计算所有DP值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = Dp[i-1][j] + 1;
                int right = Dp[i][j-1] + 1;
                int change = Dp[i-1][j-1];
                if (word1[i-1] !=  word2[j-1]) { // 如果A的第i个字符和B的第j个字符相等，则不需要进行额外操作
                    change += 1;
                }
                Dp[i][j] = min(left, min(right, change));
            }
        }
        return Dp[n][m];
    }
};