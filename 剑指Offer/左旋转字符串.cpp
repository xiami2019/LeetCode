class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n) + s.substr(0, n);
    }
};

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        //循环移位:
        while (n--){
            s 
        }
    }
};

//C语言：
char* reverseLeftWords(char* s, int n){
    int len = strlen(s), i = 0;
    char *ans = (char*)malloc(sizeof(char) * (len + 1));
    //注意malloc字符串长度的时候一定是len+1，因为最后以为还要保存'\0'；
    while (i < len){
        *(ans++) = s[(n + i++) % len];
    }
    *ans = '\0';

    return ans - len;
}