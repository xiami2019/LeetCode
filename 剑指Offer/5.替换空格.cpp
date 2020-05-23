class Solution {
public:
    string replaceSpace(string s) {
        // 先统计空格数，然后倒着替换
        int numberOfBlanks = 0;
        for (char c : s) {
            if (c == ' ') numberOfBlanks++;
        }
        int totalLength = s.length() + numberOfBlanks * 2;
        char newStr[totalLength + 1];
        newStr[totalLength] = '\0';

        int index = totalLength - 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                newStr[index--] = s[i];
            }
            else {
                newStr[index--] = '0';
                newStr[index--] = '2';
                newStr[index--] = '%';
            }
        }
        return newStr;
    }
};