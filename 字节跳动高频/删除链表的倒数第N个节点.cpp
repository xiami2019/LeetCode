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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (n--) {
            if (fast == NULL) return head;
            fast = fast->next;
        }

        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        if (head->next == NULL) {
            delete head;
            head = NULL;
        }
        else if (slow->next == NULL) {
            temp = head;
            while (temp->next != slow){
                temp = temp->next;
            }
            delete slow;
            if (temp != NULL) temp->next = NULL;
        }
        else if (head == slow) {
            head = head->next;
            delete slow;
        }
        else {
            slow->val = temp->val;
            slow->next = temp->next;
            delete temp;
        }
        return head;
    }
};