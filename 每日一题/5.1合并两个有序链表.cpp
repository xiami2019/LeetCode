/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode node(0); // dummy node
        ListNode *iter = &node; // iteration pointer
        while (l1 != nullptr && l2 != nullptr) {
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
        iter->next = l1 ? l1 : l2;
        return node.next;
    }
};