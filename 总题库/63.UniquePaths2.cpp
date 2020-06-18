class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) {
            return 0;
        }
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<int> dp(cols, 1);
        for (int i = 0; i < cols; ++i) {
            if (obstacleGrid[0][i] == 1) {
                dp[i] = 0;
            }
        }
        for (int i = 1; i < rows; ++i) {
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