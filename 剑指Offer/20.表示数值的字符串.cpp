class Solution {
public:
    bool isNumber(string &s) {
        if (s.empty()) return false;

        // 去掉首尾的空字符串
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);

        // 设置标记位
        bool point = false;
        bool e = false;
        bool number = false; // 标记是否开始读取数字
        bool numberAfterE = true; // 标记符号e之后是否有数字，如果符号e之后并没有数字，则返回false；
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                number = true;
                numberAfterE = true;
            }
            else if (s[i] == '.') {
                if (e || point) {
                    // 只能出现一个小数点并且e之后不能出现小数
                    return false;
                }
                point = true;
            }
            else if (s[i] == 'e') {
                if (e || !number) {
                    return false;
                }
                numberAfterE = false;
                e = true;
            }
            else if (s[i] == '-' || s[i] == '+') {
                if (i != 0 && s[i - 1] != 'e') {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return number && numberAfterE;
    }
};