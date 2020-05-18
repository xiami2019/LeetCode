/*
转化问题：
找出数组中任意两个数的最大差值，并且第二个数必须大于第一个数。
暴力
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricesLen = prices.size();
        int maxProfit = INT_MIN;
        for (int i = 0; i < pricesLen; i++){
            for (int j = i + 1; j < pricesLen; j++){
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxProfit > 0 ? maxProfit : 0;
    }
};

/*
一次遍历：
只需要在一次遍历的同时维护好历史最低价格，这样在遍历了一遍之后就能得出结果。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bottom = INT_MAX, maxProfit = 0;
        for (int price : prices){
            bottom = min(bottom, price);
            maxProfit = max(maxProfit, price - bottom);
        }
        return maxProfit;
    }
};

/*
动态规划：
dp[2][3][0]的含义是：今天是第二天，手上没有持有股票，至今最多进行三次交易。此时利润为多少。
dp[3][2][1]的含义是：今天是第三天，我现在手上持有者股票，至今最多进行2次交易。
base case：
dp[-1][k][0] = dp[i][0][0] = 0;
dp[-1][k][1] = dp[i][0][1] = -inf;

状态转移方程：
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])

最终要求的是：d[n-1][K][0]的值；
自底向上递归；
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int pricesLen = prices.size();
        int ifSell = 0, ifBuy = -prices[0];
        for (int i = 1; i < pricesLen; i++){
            ifSell = max(ifSell, ifBuy + prices[i]); //持有或者卖出；
            ifBuy = max(ifBuy, -prices[i]); //持有或者买入；
        }
        return ifSell;
    }
};

//当k无限时，就不需要再记录k这个变量了。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int pricesLen = prices.size();
        int Sell = 0, Buy = -prices[0];
        for (int i = 1; i < pricesLen; i++){
            int oldSell = Sell;
            Sell = max(oldSell, Buy + prices[i]);
            Buy = max(Buy, oldSell - prices[i]);
        } 
        return Sell;
    }
};