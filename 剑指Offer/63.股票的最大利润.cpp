class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int low = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - low);
            low = min(low, prices[i]);
        }
        return maxProfit;
    }
};

