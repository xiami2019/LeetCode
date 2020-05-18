/*
暴力解法
*/
class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0; // 保存结果，1出现的次数
        for (int i = 1; i <= n; i++) {
            int temp = i;
            while (temp) {
                if (temp % 10 == 1) {
                    ans++;
                }
                temp /= 10;
            }
        }
        return ans;
    }
};

/*
数学规律解法
*/
class Solution {
public:
    int countDigitOne(int n) {
        int counts = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            counts += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return counts;
    }
};