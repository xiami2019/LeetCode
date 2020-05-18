#include <bits/stdc++.h>
using namespace std;

class Solution {
//动态规划法;
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len == 1){
            return s;
        }
        int start = 0, max = 1;
        int dp[len][len] = {0};
        for(int i = 0; i < len; i++){
            dp[i][i] = 1; //所有单个字符都是回文串;
            if(i < len - 1 && s[i] == s[i+1]){ //相邻两个相同的字符是回文串;
                dp[i][i+1] = 1;
                max = 2;
                start = i;
            }
        }
        for(int i = 3; i <= len; i++){ //i代表检索子串的长度，等于3表示先检索长度为3的子串;
            for(int j = 0; j + i - 1 < len; j++){
                int k = j + i - 1; //终止字符串的位置
                if(s[j] == s[k] && dp[j+1][k-1] == 1){ //状态转移
                    dp[j][k] = 1;
                    start = j;
                    max = i;
                }
            }
        }
        return s.substr(start, max); //获取最长回文子串;
    }
};

class Solution {
//中心扩展法;
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 0 || len == 1){
            return s;
        }
        int start = 0; //记录回文子串起始位置
        int end = 0; //记录回文子串终止位置
        int maxlen = 0; //记录最大回文子串的长度
        for(int i = 0; i < len; i++){
            int len1 = expendAroundCenter(s, i, i); //以一个元素为中心
            int len2 = expendAroundCenter(s, i, i+1); //两个元素为中心
            maxlen = max(max(len1, len2), maxlen);
            if(maxlen > end - start + 1){
                start = i - (maxlen - 1) / 2;
                end = i + maxlen / 2;
            }
        }
        return s.substr(start, maxlen);
    }
private:
    int expendAroundCenter(string s, int left, int right)
    //计算以left和right为中心的回文长度;
    {
        while(left >= 0 && right < s.length() && s[right] == s[left]){
            left--;
            right++;
        }
        return right - left - 1;
    }
};

class Solution{
    //Manacher算法
    public:
        string longestPalindrome(string s){
            //特例判别
            int size = s.size();
            if(size < 2){
                return s;
            }

            //预处理字符串
            string str = "#";
            for(int i = 0; i < s.size(); i++){
                str += s[i];
                str += "#";
            }

            //新字符串的长度
            int strSize = 2 * size + 1;
            //辅助数组p记录了扫描过的回文子串的信息
            vector<int> p(strSize, 0);

            //Manacher算法的两个特殊索引，一一对应，须同时更新
            int maxRight = 0;
            int center = 0;

            //当前遍历的中心最大扩散步数，其值等于原始字符串的最长回文子串的长度
            int maxLen = 1;
            //原始字符串的最长回文子串的起始位置，与maxLen必须同时更新
            int start = 0;

            //开始Manacher算法的遍历
            for(int i = 0; i < strSize; i++){
                if(i < maxRight){
                    int mirror = 2 * center - i;
                    p[i] = min(maxRight - i, p[mirror]);
                }

                //下一次尝试扩散的左右起点，能扩散的步数直接加到p[i]中
                int left = i - (1 + p[i]);
                int right = i + (1 + p[i]);
                while(left >= 0 && right < strSize && str[left] == str[right]){
                    p[i]++;
                    left--;
                    right++;
                }
                //根据maxRight的定义，它是遍历过的i的i+p[i]的最大者
                //如果maxRight的值越大，进入上面i < maxRight的判断可能性就越大，这样就可以重复利用
                //之前判断过的回文信息了。
                if(i + p[i] > maxRight){
                    maxRight = i + p[i];
                    center = i;
                }
                if(p[i] > maxLen){
                    maxLen = p[i];
                    start = (i - maxLen) / 2;
                }
            }
            return s.substr(start, maxLen);
        }
};

int main()
{

}