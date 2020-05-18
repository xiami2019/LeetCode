//DFS
class Solution {
public:
    int ans = INT_MAX;

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        dfs(coins, coins.size() - 1, amount, 0);
        return ans == INT_MAX ? -1 : ans;
    }

    void dfs(vector<int>& coins, int index, int amount, int cnt)
    {
        if (index < 0){
            return;
        }
        for (int c = amount / coins[index]; c >= 0; c--){ //大面值从多到少
            int remains = amount - c * coins[index];
            int tempcnt = cnt + c;
            if (remains == 0){ //已经完成了一种分配方案
                this->ans = min(this->ans, tempcnt);
                break;
            }
            if (tempcnt >= ans){
                break;
            }

            dfs(coins, index - 1, remains, tempcnt);
        }
    }
};

//自上而下DP
/*

F(S): 组成金额S所需的最少硬币数量；
[c0, ... ,c_(n-1)]：可选的n枚硬币面额值；
这个问题有一个最优的子结构性质，这是解决动态规划问题的关键。
最优解可以从其子问题的最优解构造出来。假设我们知道F(S)，即组成金额S最少的硬币数，
最后一枚硬币的面值是C，那么由于问题的最优子结构，转移方程应为：
F(S) = F(S - C) + 1
但我们不知道最后一枚硬币的面值是多少，所以我们要枚举每个硬币面额值c0，c1，c2，...，c_(n-1), 并选择其中的最小值。
当S=0时，F(S) = 0；当n = 0时，F(S) = -1；
*/
class Solution {
public:
    vector<int> count; //存储组成金额S所需的最少硬币数量。
    int dp(vector<int> &coins, int rem)
    {
        if (rem < 0) return -1;
        if (rem == 0) return 0;
        //动态规划记忆数组；
        if (count[rem - 1] != 0) return count[rem - 1];
        int Min = INT_MAX;
        for (int coin : coins){
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < Min){
                Min = res + 1;
            }
        }
        count[rem - 1] = Min == INT_MAX ? -1 : Min;
        return count[rem - 1];
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        count.resize(amount);
        return dp(coins, amount);
    }
};

/*
自下而上DP
采用自下而上的方式进行思考。仍定义F(i)为组成金额i所需最少的硬币数量，假设在计算F(i)之前，我们已经计算出F(0)至F(i-1)
的答案。则F(i)对应的状态转移方程应为：
F(i) = min(j=0~n-1) F(i-c_j) + 1
其中c_j代表的是第j枚硬币的面值，即我们枚举最后一枚硬币面额是c_j，那么需要从i-c_j这个金额的状态F(i-c_j)转移过来，再算上
枚举的这枚硬币数量1的贡献，由于要硬币数量最少，所以F(i)为前面能转移过来的状态的最小值加上枚举的硬币数量1.
当i == 0时无法用硬币组成，为0。当i < 0时，忽略F(i);
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i){
            for (int j = 0; j < (int)coins.size(); ++j){
                if (coins[j] <= i){
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        //因为是用Max初始化的，所以如果大于amount就说明没有改变，无法组成指定的金额。
        return dp[amount] > amount ? -1 : dp[amount];
    }
};