//采用分治法处理；

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0){
            return 1;
        }

        double temp = myPow(x, n / 2);
        double result = temp * temp;
        if (n & 1){ //采用位运算的方式判断是奇数还是偶数；
            if (n < 0) result /= x;
            else result *= x;
        }

        return result;
    }
};