class Solution {
    int numberCountsOfSinglePrefix(int prefix, int n) {
        int counts = 0;
        long cur = prefix, next = prefix + 1;
        while (cur <= n) {
            // 下一个前缀的起点减去当前前缀的起点
            if (next < n + 1) counts += next - cur;
            else counts += n + 1 - cur;
            cur *= 10;
            next *= 10;
        }
        return counts;
    }

public:
    int findKthNumber(int n, int k) {
        long p = 1; // 用于指出当前的位置，即是第几小的数字
        int prefix = 1; // 前缀
        while (p < k) {
            int counts = this->numberCountsOfSinglePrefix(prefix, n);
            if (p + counts > k) { // 第k个数在当前前缀下
                prefix *= 10; // 前进一步
                p++; // 把指针指向第一个子节点的位置
            } 
            else if (p + counts <= k) { // 第k个数不在当前前缀下
                prefix++; // 切换前缀
                p += counts; // 指针指向下一个前缀的起点
            }
        }
        return prefix;
    }
};