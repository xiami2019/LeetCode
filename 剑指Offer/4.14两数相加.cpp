/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
法一：使用辅助内存将链表保存为字符串
*/
class Solution {
    string listToString(ListNode* l1) {
        string result = "";
        if (l1 == NULL) {
            return result;
        }
        while (l1 != NULL) {
            result += '0' + l1->val;
            l1 = l1->next;
        }
        return result;
    }

    string stringAdd(string s1, string s2) {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        string result = "";
        int carry = 0;
        int s1Len = s1.length(), s2Len = s2.length();
        for (int i = 0; i < s1Len || i < s2Len; i++) {
            int pointSum = 0;
            if (i >= s1Len) {
                pointSum = (char)(s2[i] - '0') + carry;
            }
            else if (i >= s2Len) {
                pointSum = (char)(s1[i] - '0') + carry;
            }
            else {
                pointSum = (char)(s1[i] - '0') + (char)(s2[i] - '0') + carry;
            }

            if (pointSum >= 10) {
                pointSum %= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            result = (char)('0' + pointSum) + result;
        }
        if (carry > 0) {
            result = (char)('0' + carry) + result;
        }

        return result;
    }

    ListNode* stringToList(string s1) {
        ListNode dummy(0);
        dummy.next = NULL;
        ListNode* temp = &dummy;
        int s1Len = s1.length();
        for (int i = 0; i < s1Len; i++) {
            temp->next = new ListNode((char)(s1[i] - '0'));
            temp = temp->next;
        }
        return dummy.next;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1 = this->listToString(l1);
        string s2 = this->listToString(l2);
        string stringSum = this->stringAdd(s1, s2);
        ListNode* ans = this->stringToList(stringSum);
        return ans;
    }
};

/*
法二：栈
本题的主要难点在于链表中数位的顺序与我们做加法的顺序是相反的，为了逆序处理所有数位，我们
可以使用栈：把所有数字压入栈中，再依次取出相加。计算过程中需要注意进位的情况。
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* ans = NULL;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            auto curnode = new ListNode(cur);
            curnode->next = ans;
            ans = curnode;
        }
        return ans;
    }
};