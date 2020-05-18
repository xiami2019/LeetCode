class Solution {
public:
    int myAtoi(string str){
        bool negative = false; // 适用于没出现正负号默认为整数的情况
        int index = 0; // 索引
        long long result = 0;

        while (index < str.size() && str[index] == ' '){
            index++; // 指向第一个非空格字符；
        }

        if (index == str.size()){ // 字符串全部为空字符
            return 0;
        }

        if (str[index] == '-'){
            negative = true; //正负号判定；
            index++;
        }
        else if (str[index] == '+'){
            negative = false;
            index++;
        }

        while (index < str.size() && isdigit(str[index])){
            result = result * 10 + str[index++] - '0'; // 没有到字符串尾且依然是数字；
            if (result >= 2147483648){ //int溢出判定；
                if (negative) return INT_MIN;
                else return INT_MAX;
            }
        }
        return negative ? result * (-1) : result;
    }
};