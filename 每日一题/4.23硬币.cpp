/*
方法一：动态规划（背包问题）
*/

class Solution {
private:
    static constexpr int mod = 1000000007;
    static constexpr int coins[4] = {25, 10, 5, 1};

public:
    int waysToChange(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        for (int c = 0; c < 4; c++) {
            int coin = coins[c];
            for (int i = coin; i <= n; i++) {
                f[i] = (f[i] + f[i - coin]) % mod;
            }
        }
        return f[n];
    }
};


/*
数学
对于给定的n，我们先枚举25分的硬币的个数i，那么剩下的部分我们记为 r = n - 25 * i，r可以表示成：
r = 10 * a + 5 * b + c;
这里a能取的最大值a0 = r - (r mod 10)，当a=a0时限定c < 5可以得到这种情况下b的最大值b0，那么令
c0 = r - 10 * a0 - 5 * b0;
考虑选择i个25分硬币的时候的情况，假设我们选择x个10分硬币，那么还剩下的金额我们可以表示为：
10 * (a0 - x) + 5 * b0 + c0;
考虑把10 * (a0 - x)这一项全部用5分硬币来替代，即上面的式子可以转化成5(2a0 - 2x + b0) + c0，那么
5分硬币可以选择的范围是[0, 2a0 - 2x + b0]，剩下的用1分硬币补齐。也就是说对于25分取i个，10分取x个
的时候方案总数为2a0 - 2x + b0 + 1，对x求和：
sum(x=0 ~ a0)(2a0 - 2x + b0 + 1) = (a0 + 1)(a0 + b0 + 1)
我们就可以得到25分取i个的时候的方案总数，枚举i并累加即可获得最终的答案。
*/
class Solution {
    static constexpr int mod = 1000000007;
public:
    int waysToChange(int n) {
        int ans = 0;
        for (int i = 0; i * 25 <= n; i++) {
            int rest = n - i * 25;
            int a = rest / 10;
            int b = rest % 10 / 5;
            ans = (ans + (long long)(a + 1) * (a + b + 1) % mod) % mod;
        }
        return ans;
    }
};
