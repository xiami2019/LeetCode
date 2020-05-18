#include <bits/stdc++.h>
using namespace std;

//思路: 滑动窗口;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, len = 0, result = 0;
        int str_len = s.length();
        while(end < str_len){
            char tempChar = s[end];
            for(int index = start; index < end; index++){
                if(tempChar == s[index]){
                    start = index + 1;
                    len = end - start;
                    break;
                }
            }
            end++;
            len++;
            result = max(result, len);
        }
        return result;
    }
};

//用map代替检索;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, len = 0, result = 0;
        int str_len = s.length();
        map<char, int> hashmap;
        while(end < str_len){
            char tempChar = s[end];
            if(hashmap.count(tempChar) > 0){
                if(start <= hashmap[tempChar]){
                    start = hashmap[tempChar] + 1;
                    len = end - start;
                }
            }
            hashmap[tempChar] = end;
            end++;
            len++;
            result = max(result, len);
        }
        return result;
    }
};

int main()
{
    Solution solu;
    cout << solu.lengthOfLongestSubstring("abcabcabcbbbbbb");
}