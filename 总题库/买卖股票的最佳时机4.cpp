class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        int pricesLen = prices.size();
        if (k > pricesLen / 2) return maxProfitInf(prices);
        int dp[pricesLen][k+1][2];

        for (int i = 0; i < pricesLen; i++){
            for (int j = k; j >= 1; j--){
                if (i == 0){
                    if (j == 0){
                        dp[i][j][0] = 0;
                        dp[i][j][1] = 0;
                        continue;
                    }
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }
                if (j == 0){
                    continue;
                }
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);   
            }
        } 
        return dp[pricesLen-1][k][0];
    }

    int maxProfitInf(vector<int>& prices) {
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