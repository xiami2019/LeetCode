/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 使用哑节点可以使用循环
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode dummy(0);
        ListNode *iter = &dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                iter->next = l1;
                l1 = l1->next;
            }
            else {
                iter->next = l2;
                l2 = l2->next;
            }
            iter = iter->next;
        }
        while (l1 != NULL) {
            iter->next = l1;
            l1 = l1->next;
            iter = iter->next;
        }
        while (l2 != NULL) {
            iter->next = l2;
            l2 = l2->next;
            iter = iter->next;
        }
        return dummy.next;
    }
};