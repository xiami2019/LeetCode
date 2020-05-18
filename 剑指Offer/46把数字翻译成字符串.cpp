/*
从数字的末尾开始，从右向左翻译，解决自上而下计算时子问题重复的问题；
*/

class Solution {
public:
    int translateNum(int num) {
        if (num < 0) {
            return 0;
        }
        string numStr = to_string(num);
        int strLen = numStr.length();
        int post1 = 0, post2 = 0; // 当前数往后的第一个数和第二个数
        int count = 0;

        for (int i = strLen - 1; i >= 0; i--) {
            count = 0;
            if (i < strLen - 1) {
                count = post1;
                int temp = (numStr[i] - '0') * 10 + numStr[i + 1] - '0';
                if (temp >= 10 && temp <= 25) {
                    if (i < strLen - 2) {
                        count += post2;
                    }
                    else {
                        count += 1;
                    }
                }
            }
            else {
                count = 1;
            }

            post2 = post1;
            post1 = count;
        }
        return post1;
    }
};