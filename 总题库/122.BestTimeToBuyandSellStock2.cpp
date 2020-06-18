// 峰谷法；
// 先找一个低谷，再找根它紧接着的峰值；
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int index = 0;
        int valley = prices[0];
        int peak = prices[0];
        int res = 0;
        while (index < prices.size()) {
            while (index + 1 < prices.size() && prices[index] > prices[index + 1]) {
                ++index;
            }
            valley = prices[index];
            while (index + 1 < prices.size() && prices[index] < prices[index + 1]) {
                ++index;
            }
            peak = prices[index];
            if (peak > valley) {
                res += peak - valley;
            }
            ++index;
        }
        return res;
    }
};

// 一次遍历法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
};

// DP
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