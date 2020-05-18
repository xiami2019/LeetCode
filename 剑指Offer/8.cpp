/*
青蛙跳台阶，实质就是斐波那契数列
*/
class Solution {
public:
    int numWays(int n) {
        if (n == 0 || n == 1) return 1;
        long steps[n+1] = {0};
        steps[0] = 1; steps[1] = 1;
        for (int i = 2; i <= n; i++){
            steps[i] = steps[i-1] + steps[i-2];
            steps[i] %= 1000000007;
        }
        return steps[n];
    }
};