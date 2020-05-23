class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int preNum1 = 1, preNum2 = 0, temp;
        n -= 1;
        while (n--) {
            temp = preNum2;
            preNum2 = preNum1;
            preNum1 = preNum2 + temp;
            preNum1 %= 1000000007;
        }
        return preNum1;
    }
};