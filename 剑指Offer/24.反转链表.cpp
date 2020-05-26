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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* tail = NULL;
        while (head != NULL) {
            ListNode* temp = head;
            head = head->next;
            temp->next = tail;
            tail = temp;
        }
        return tail;
    }
};