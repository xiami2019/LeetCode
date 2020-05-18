typedef long long ll;

class Solution {
    // 计算一块披萨中是否存在A；
    bool hasA(vector<vector<int>>& nums, int sr, int sc, int er, int ec) {
        int num1 = 0, num2 = 0, num3 = 0;
        if (sr != 0 && sc != 0) num1 = nums[sr - 1][sc - 1];
        if (sr != 0) num2 = nums[sr - 1][ec];
        if (sc != 0) num3 = nums[er][sc - 1];
        return nums[er][ec] - num2 - num3 + num1 > 0;
    }

public:
    const ll mod = 1e9+7;
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].length();
        // 计算num；
        vector<vector<int> > nums(rows, vector<int>(cols, 0));
        if (pizza[0][0] == 'A') nums[0][0] = 1;
        for (int i = 1; i < rows; i++) {
            nums[i][0] = nums[i - 1][0] + (pizza[i][0] == 'A');
        }
        for (int i = 1; i < cols; i++) {
            nums[0][i] = nums[0][i - 1] + (pizza[0][i] == 'A');
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                nums[i][j] = nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1] + (pizza[i][j] == 'A');
            }
        }

        // 初始化dp
        vector<vector<vector<ll>>> dp(rows, vector<vector<ll>>(cols, vector<ll>(k + 1, 0)));
        dp[0][0][1] = 1;

        // 从k=2开始填充
        for (int x = 2; x <= k; x++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    // dp为0代表不存在这种情况
                    if (dp[i][j][x - 1] == 0) {
                        continue;
                    }

                    // 穷举水平切
                    for (int z = i + 1; z < rows; z++) {
                        if (hasA(nums, i, j, z - 1, cols - 1) && hasA(nums, z, j, rows - 1, cols - 1)) {
                            dp[z][j][x] += dp[i][j][x - 1];
                            dp[z][j][x] %= mod;
                        }
                    }

                    // 穷举垂直切
                    for (int z = j + 1; z < cols; z++) {
                        if (hasA(nums, i, j, rows - 1, z - 1) && hasA(nums, i, z, rows - 1, cols - 1)) {
                            dp[i][z][x] += dp[i][j][x - 1];
                            dp[i][z][x] %= mod;
                        }
                    }
                }
            }
        }
        // 计算答案
        ll ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans += dp[i][j][k];
            }
            ans %= mod;
        }
        return ans;
    } 
};