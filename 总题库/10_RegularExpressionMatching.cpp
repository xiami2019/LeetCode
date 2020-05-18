/*
正则表达式匹配：
方法1：回溯
想法：如果没有星号（正则表达式中的*），问题会很简单——我们只需要从左到右检查匹配串s是否能匹配模式串p的每一个字符
当模式串中有星号时，我们需要检查匹配串s中的不同后缀，以判断它们是否能匹配模式串剩余的部分。一个直观的解法就是用
回溯的方法来体现这种关系。
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int index_s = 0; //s的索引；
        int index_p = 0; //p的索引；
        while (index_s < s.length()){
            if (index_p >= p.length()){ //说明两个字符串长短不一致，无法匹配；
                return false;
            }
            if (s[index_s] == p[index_p]){ //
                index_s++;
                index_p++;
            }
            else if (p[index_p] == '.'){
                index_s++;
                index_p++;
            }
            else if (p[index_p] == '*'){
                if (p[index_p - 1] == s[index_s] || p[index_p - 1] == '.'){
                    index_s++;
                }
                else index_p++;
            }
            else if (index_p < p.length() - 1 && p[index_p + 1] == '*'){
                index_p += 2;
            }
            else return false;
        }
        if(index_p < p.length() - 1 && p[index_p] == '*'){
            char temp = p[index_p - 1];
            while(index_p + 1 < p.length() && temp == p[index_p + 1]) index_p++;
        }
        if (index_p == p.length() || (index_p + 1 == p.length() && p[index_p] == '*')) return true;
        else return false;
    }
};