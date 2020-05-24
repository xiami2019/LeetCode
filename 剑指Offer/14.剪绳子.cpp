class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2) return 0;
        if (n == 2) return 1;
        if (n == 3) return 2;

        vector<int> dpTable(n + 1, 0);
        dpTable[0] = 0;
        dpTable[1] = 1;
        dpTable[2] = 2;
        dpTable[3] = 3;

        int maxProduct;
        for (int i = 3; i <= n; ++i) {
            maxProduct = 0;
            for (int j = i; j <= n / 2; ++j) {
                maxProduct = max(maxProduct, dpTable[j] * dpTable[n - j]);
            }
            dpTable[i] = maxProduct;
        }
        return dpTable[n];
    }
};