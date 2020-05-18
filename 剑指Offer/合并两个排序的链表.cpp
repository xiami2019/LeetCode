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
    //考虑好边界条件，直接归并完事；
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL){
            return l2;
        }
        if (l2 == NULL){
            return l1;
        }

        ListNode* l3 = new ListNode(0);
        ListNode* temp = l3;

        while (l1 != NULL || l2 != NULL){
            if (l1 == NULL || (l2 != NULL && l2->val <= l1->val)){ //注意取等的情况
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
                temp = temp->next;
            }
            else if (l2 == NULL || (l1 != NULL && l1->val < l2->val)){
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
                temp = temp->next;
            }
        }

        temp = l3;
        l3 = l3->next;
        delete temp;

        return l3;
    }
};