/*
暴力法：枚举每一位数字，看位数有没有超，先锁定正确的数字，再查找对应的位；
*/

class Solution {
public:
    int findNthDigit(int n) {
        int number = 0;
        int bitsSum = 0;
        while (bitsSum < n) {
            int tempBits = 0;
            int tempNumber = number;
            if (tempNumber == 0) tempBits = 0;
            else {
                while (tempNumber) {
                    tempBits++;
                    tempNumber /= 10;
                }
            }
            bitsSum += tempBits;
            if (bitsSum < n) {
                number++;
            } 
        }
        
        int pos = bitsSum - n;
        string numberStr = to_string(number);
        return numberStr[numberStr.length() - 1 - pos] - '0';
    }
};

/*
找规律法:
找出某些规律从而跳过若干数字；

注意int的溢出问题；
*/
class Solution {
    long long countOfIntegers(int digits) {
        // 得到 m位的数字总共有多少个
        if (digits == 1) {
            return 10;
        }
        long long count = (int)pow(10, digits - 1);
        return (long long)9 * count;
    }

    long long beginNumber(int digits) {
        if (digits == 1) return 0;
        return (long long) pow(10, digits - 1);
    }

    int digitAtIndex(long long index, int digits) {
        // 当知道要找的那一位数字位于某m位数之中后，通过这个函数找出那个数字
        long long number = this->beginNumber(digits) + index / digits;
        int indexFromRight = digits - index % digits;
        for (int i = 1; i < indexFromRight; i++) {
            number /= 10;
        }
        return number % 10;
    }

public:
    int findNthDigit(int n) {
        if (n < 0) return -1;
        int digits = 1;
        while (1) {
            long long numbers = this->countOfIntegers(digits); // 计算当前位数有多少个数字
            if (n < numbers * digits) {
                // 已经越界了
                return this->digitAtIndex(n, digits);
            }
            n -= digits * numbers;
            digits++;
        }
        return -1;
    }
};