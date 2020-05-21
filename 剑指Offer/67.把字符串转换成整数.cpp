class Solution {
public:
    int strToInt(string str) {
        if (str == "") return 0; // 可以设置一个全局变量来检测输入是否非法
        int index = 0;
        long long ans = 0;
        // 消除空字符
        while (str[index] == ' ') index++;

        int negative = 1;
        if (str[index] == '-') {
            negative = -1;
            index++;
        }
        else if (str[index] == '+') {
            index++;
        }
        if (str[index] < '0' || str[index] > '9') {
            return 0;
        }
        while (str[index] >= '0' && str[index] <= '9') {
            ans = ans * 10 + (str[index] - '0');
            if (ans * negative > INT_MAX) return INT_MAX;
            if (ans *negative < INT_MIN) return INT_MIN;
            index++;
        }
        return ans * negative;
    }
};