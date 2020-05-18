class Solution {
public:
    string reverseWords(string s) {
        // 先翻转整个字符串
        reverse(s.begin(), s.end());
        int strLen = s.length();
        int idx = 0;
        for (int start = 0; start < strLen; start++) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0) s[idx++] = ' ';

                // 遍历至单词的词尾
                int end = start;
                while (end < strLen && s[end] != ' ')  s[idx++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};