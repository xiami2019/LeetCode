class Solution {
public:
    string replaceSpace(string s) {
        if (s == "") return s;

        //计算字符串的实际长度；
        int originalLength = 0;
        int nunmberOfBlank = 0;
        for (char c: s){
            if (c == ' '){
                nunmberOfBlank++;
            }
            originalLength++;
        }

        //计算替换后字符串的长度；
        int newLength = originalLength + nunmberOfBlank * 2;
        int indexOfOriginal = originalLength - 1;
        int indexOfNew = newLength - 1;
        char newString[newLength + 1];
        newString[newLength] = '\0';
        while (indexOfOriginal >= 0){
            if (s[indexOfOriginal] == ' '){
                newString[indexOfNew--] = '0';
                newString[indexOfNew--] = '2';
                newString[indexOfNew--] = '%';
            }
            else {
                newString[indexOfNew--] = s[indexOfOriginal];
            }
            indexOfOriginal--;
        }
        return newString;
    }
};