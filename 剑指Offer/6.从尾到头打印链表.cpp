/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 递归实现
class Solution {
    vector<int> ans;
    void reversePringHelper(ListNode* head) {
        if (head == NULL) {
            return;
        }

        reversePringHelper(head->next);
        ans.emplace_back(head->val);
    }

public:
    vector<int> reversePrint(ListNode* head) {
        reversePringHelper(head);
        return ans;
    }
};