class Solution {
public:
    int numWays(int n) {
        if (n < 2) return 1;
    
        int index = 2;
        int oneStep = 1;
        int twoStep = 0;
        int temp;
        while (index <= n) {
            temp = twoStep;
            twoStep = oneStep;
            oneStep = temp + twoStep;
            oneStep %= 1e9 + 7;
        }
        return oneStep;
    }
};