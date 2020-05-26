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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (k == 0) return NULL;
        ListNode *fast = head, *slow = head;
        while (k--){
            if (fast == NULL) return NULL;
            fast = fast->next;
        }
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};