/*
dp的目标是将一个区间删除完毕的最小代价；从较小的区间开始，易知长为1的区间代价一定为1，长为2的区间为1或2，取决于是否回文。
*/
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int arrLen = arr.size();
        if (arrLen == 0) return 0;
        int dp[101][101]; // 区间DP，dp[i][j]表示将子数组arr[i,...,j]删除的最小代价；
        // 先处理基本情况，对于区间长度为1的子数组，显然删除操作只需要一步；
        for (int i = 0; i < arrLen; ++i) {
            dp[i][i] = 1;
        }
        // 对于长度为2的子数组，如果是回文（即两个元素相同），则删除只需要一步，否则需要两步
        for (int i = 0; i < arrLen - 1; ++i) {
            if (arr[i] == arr[i + 1]) {
                dp[i][i + 1] = 1;
            }
            else {
                dp[i][i + 1] = 2;
            }
        }
        // 对于长度大于等于3的子数组，
        for (int len = 2; len < arrLen; ++len) {
            for (int i = 0; i < arrLen - len; ++i) {
                dp[i][i + len] = len + 1;
                for (int k = 0; k < len; ++k) {
                    if (dp[i][i + len] > dp[i][i + k] + dp[i + k + 1][i + len]) {
                        dp[i][i + len] = dp[i][i + k] + dp[i + k + 1][i + len];
                    }
                }
                if (arr[i] == arr[i + len] && dp[i][i + len] > dp[i + 1][i + len - 1]) {
                    dp[i][i + len] = dp[i + 1][i + len - 1];
                }
            }
        }
        return dp[0][arrLen - 1];
    }
};