class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<long> uglyNumbers(n); // 已经存在的排序的丑数
        int index = 0;
        uglyNumbers[0] = 1;
        while (index < n - 1) {
            long minNumber = INT_MAX;
            for (int i = 0; i <= index; i++) {
                if (uglyNumbers[i] * 2 > uglyNumbers[index]) {
                    minNumber = min(minNumber, uglyNumbers[i] * 2);
                }
                if (uglyNumbers[i] * 3 > uglyNumbers[index]) {
                    minNumber = min(minNumber, uglyNumbers[i] * 3);
                }
                if (uglyNumbers[i] * 5 > uglyNumbers[index]) {
                    minNumber = min(minNumber, uglyNumbers[i] * 5);
                }
            }
            uglyNumbers[++index] = minNumber;
        }

        return uglyNumbers[index];
    }
};