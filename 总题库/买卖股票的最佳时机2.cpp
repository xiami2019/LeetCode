class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int pricesLen = prices.size();
        int dp[pricesLen][2];
        int Sell = 0, Buy = -prices[0];
        for (int i = 1; i < pricesLen; i++){
            int oldSell = Sell;
            Sell = max(oldSell, Buy + prices[i]);
            Buy = max(Buy, oldSell - prices[i]);
        } 
        return Sell;
    }
};