/*
法1：枚举法；
时间复杂度: O((len1 + len2))
*/
class Solution {
public:
    //检查字符串t拼接多次后能否组成字符串s；
    bool check(string t, string s){
        int lenx = (int)s.length() / (int)t.length();
        string ans = "";
        for (int i = 0; i < lenx; i++){
            ans = ans + t;
        }
        return ans == s;
    }

    string gcdOfStrings(string str1, string str2) {
        int len1 = (int)str1.length(), len2 = (int)str2.length();
        //按字符串长度由大到小进行枚举
        for (int i = min(len1, len2); i >= 1; i--){
            if (len1 % i == 0 && len2 % i == 0){ //符合条件的前缀一定是str1和str2的公约数；
                string commonString = str1.substr(0, i);
                if (check(commonString, str1) && check(commonString, str2)){
                    return commonString;
                }
            }
        }
        return "";    
    }
};

/*
枚举优化：
说白了就是找最大公约数，所以找出两个字符串的最大公约数即可；
最大公约数可以通过字符串的长度来求出，然后直接从头开始截取即可；
*/
class Solution {
public:
    //检查字符串t拼接多次后能否组成字符串s；
    bool check(string t, string s){
        int lenx = (int)s.length() / (int)t.length();
        string ans = "";
        for (int i = 0; i < lenx; i++){
            ans = ans + t;
        }
        return ans == s;
    }

    int gcd(int a, int b){
        if (a < b){
            int temp = a;
            a = b;
            b = temp;
        }
        if (a % b == 0){
            return b;
        }
        else return gcd(b, a % b);
    }

    string gcdOfStrings(string str1, string str2) {
        int len1 = (int)str1.length(), len2 = (int)str2.length();
        int gcdLength = gcd(len1, len2);
        string commonString = str1.substr(0, gcdLength);
        if (check(commonString, str1) && check(commonString, str2)){
            return commonString;
        }
        return "";    
    }
};

/*
方法三：
如果str1和str2拼接后等于str2和str1拼接起来的字符串（注意拼接顺序不同），那么一定存在符合条件的字符串X
*/
class Solution {
public:
    int gcd(int a, int b){
        if (a < b){
            int temp = a;
            a = b;
            b = temp;
        }
        if (a % b == 0){
            return b;
        }
        else return gcd(b, a % b);
    }

    string gcdOfStrings(string str1, string str2) {
        int gcdLen = gcd(str1.length(), str2.length());
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0,gcdLen);
    }
};