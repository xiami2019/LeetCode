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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* index = head;
        if (head->val == val){
            head = head->next;
            // delete index;
            return head;
        }
        while (index->next != NULL && index->next->val != val){
            index = index->next;
        }
        if (index->next != NULL){
            ListNode* temp = index->next;
            index->next = index->next->next;
            delete temp;
        }
        return head;
    }
};