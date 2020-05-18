/*
方法一：动态规划；
这个问题可以通过动态规划解决。定义一个dp数组，其中第i个元素表示以下标为i的字符结尾的最长有效子字符串的长度。
将dp数组全部初始化为0。则很明显有效的子字符串一定以")"结尾。这进一步可以得出结论：以"("结尾的子字符串对应的
dp数组位置上的值必定为0。所以说我们只需要更新")"在dp数组中对应位置的值。
为了求出dp数组，我们每两个字符检查一次，如果满足如下条件
1. s[i] == ')'且s[i-1]='('，也就是字符串形如"......()"，我们可以推出：dp[i] = dp[i-2] + 2;
我们可以进行这样的转移，是因为结束部分的"()"是一个有效字符串，并且将之前有效字符串的长度增加了2。
2. s[i] == ')'且s[i-1]=')'，也就是字符串形如"......))"，我们可以推出：
如果：s[i-dp[i-1]-1]='('，
那么dp[i] = dp[i-1] + dp[i-dp[i-1]-2]+2

时间复杂度：O(n)。遍历整个字符串一次，就可以将dp数组求出来。
空间复杂度：O(n)。需要一个大小为n的dp数组。
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int sLen = s.length();
        if (sLen <= 1) return 0;

        int dpTable[sLen];
        memset(dpTable, 0, sizeof(int) * sLen);
        dpTable[0] = 0;
        if (s[1] == ')' && s[0] == '(') dpTable[1] = 2;
        else dpTable[1] = 0;
        int maxLength = dpTable[1];
        for (int i = 2; i < sLen; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dpTable[i] = dpTable[i - 2] + 2;
                }
                if (s[i - 1] == ')') {
                    if (i - dpTable[i - 1] - 1 < 0) {
                        dpTable[i - 1] = 0;
                    }
                    else if (s[i - dpTable[i - 1] - 1] == '(') {
                        if (i - dpTable[i - 1] - 2 >= 0)
                        dpTable[i] = dpTable[i - 1] + dpTable[i - dpTable[i - 1] - 2] + 2;
                        else dpTable[i] = dpTable[i - 1] + 2;
                    }
                }
                maxLength = max(maxLength, dpTable[i]);
            }
        }
        return maxLength;
    }
};

/*
方法二：栈
与找到每个可能的字符串后再判断它的有效性不同，我们可以用栈再遍历给定字符串的过程中去判断到目前为止
扫描的子字符串的有效性。首先将-1放入栈顶。

对于遇到的每个"("，我们将它的下标放入栈中。
对于遇到的每个")"，我们弹出栈顶的元素并将当前元素的下标与弹出元素下标作差，得出当前有效括号字符串的长度。通过这种方法，继续计算有效子字符串的长度，
并最终返回最长有效子字符串的长度。
复杂度分析：
时间复杂度：O(n)。n是给定字符串的长度。
空间复杂度：O(n)。栈的大小最大达到n。
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength = 0;
        stack<int> signs;
        signs.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                signs.push(i);
            }
            else {
                signs.pop();
                if (signs.empty()) {
                    signs.push(i);
                }
                else {
                    maxLength = max(maxLength, i - signs.top());
                }
            }
        }
        return maxLength;
    }
};

/*
方法三：不需要额外的空间
在这种方法中，利用两个计数器left和right。首先，我们从左到右遍历字符串，对于遇到的每个"("，我们
增加left计数器，对于遇到的每个")"我们增加right计数器。每当left计数器与right计数器相等时，计算
当前有效字符串的长度，并且记录目前为止找到的最长子字符串。如果right计数器比left计数器大时，我们
将left和right计数器同时变为0。
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            }
            else {
                right++;
            }

            if (left == right) {
                maxLength = max(maxLength, 2 * right);
            }
            else if (right >= left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            }
            else {
                right++;
            }

            if (left == right) {
                maxLength = max(maxLength, 2 * left);
            }
            else if (left >= right) {
                left = right = 0;
            }
        }
        return maxLength;
    }
};