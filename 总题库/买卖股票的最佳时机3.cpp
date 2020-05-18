//k==2，时的情况；
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int pricesLen = prices.size();
        int firstSell = 0, firstBuy = -prices[0], secondSell = 0, secondBuy = -prices[0];
        for (int i = 0; i < pricesLen; i++){
            secondSell = max(secondSell, secondBuy + prices[i]);
            secondBuy = max(secondBuy, firstSell - prices[i]);
            firstSell = max(firstSell, firstBuy + prices[i]);
            firstBuy = max(firstBuy, -prices[i]);
        } 
        return secondSell;
    }
};