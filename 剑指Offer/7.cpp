/*
斐波那契数列:
使用递归会超时，使用动态规划处理；
*/
class Solution {
public:
    int fib(int n) {
        if (n == 0){
            return 0;
        }
        else if (n == 1){
            return 1;
        }
        long long numbers[n+1] = {0};
        numbers[0] = 0, numbers[1] = 1;
        for (int i = 2; i <= n; i++){
            numbers[i] = numbers[i - 1] + numbers[i - 2];
            numbers[i] %= 1000000007;
        }
        return numbers[n];
    }
};
