class Solution {
public:
    int superEggDrop(int K, int N) {
        if (N == 1) {
            return 1;
        }

        vector<vector<int> > f(N+1, vector<int>(K+1));
        for (int i = 1; i <= K; i++) {
            f[1][i] = 1;
        }
        int ans = -1;
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                f[i][j] = 1 + f[i-1][j-1] + f[i-1][j];
            }

            if (f[i][K] >= N) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

/*
动态规划加二分查找
*/
class Solution {
    unordered_map<int, int> memo;
    int dp (int K, int N) {
        if (memo.find(N * 100 + K) == memo.end()) {
            // dp表中不存在
            int ans;
            if (N == 0) ans = 0;
            else if (K == 1) ans = N;
            else {
                int lo = 1, hi = N; // 开始二分查找
                while (lo + 1 < hi) { // 找到lo和hi相邻的lo
                    int x = (lo + hi) / 2;
                    int t1 = dp(K - 1, x - 1);
                    int t2 = dp(K, N - x);

                    if (t1 < t2) lo = x;
                    else if (t1 > t2) hi = x;
                    else lo = hi = x;
                }
                ans = 1 + min(max(dp(K - 1, lo - 1), dp(K, N - lo)), max(dp(K - 1, hi - 1), dp(K, N - hi)));
            }
            memo[N*100 + K] = ans;
        }
        return memo[N*100 + K];
    }

public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};