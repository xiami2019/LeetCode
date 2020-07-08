class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) {
            // 如果grid为空则退出程序；
            return 0;
        }
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<int> dp(cols, 1); // 建立DP数组，dp[i]的含义是到达当前行的第i个元素的不同路径有dp[i]条；
        bool flag = false; // 用来标记是否已经出现了障碍；
        for (int i = 0; i < cols; ++i) { // 初始化DP数组；
            if (obstacleGrid[0][i] == 1 || flag) { // 如果当前位置为障碍，或者在障碍的右边，则无法到达该位置，dp[i]设为0，标记为置为true；
                dp[i] = 0;
                flag = true;
            }
        }
        int index = rows; // index表示第一列的第一个障碍的位置
        for (int i = 0; i < rows; ++i) {
            if (obstacleGrid[i][0] == 1) {
                index = i;
                break;
            }
        }

        for (int i = 1; i < rows; ++i) {
            if (i >= index) {
                // 第一列障碍之下的元素是无法到达的，dp[0]置为0；
                dp[0] = 0;
            }
            for (int j = 1; j < cols; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                }
                else {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[cols - 1];
    }
};