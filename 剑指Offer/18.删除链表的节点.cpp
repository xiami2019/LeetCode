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
        if (head == NULL) return head;
        ListNode* temp = head;
        if (head->val == val) {
            // 要删除的是头节点
            head = head->next;
            // delete temp;
            return head;
        }
        
        while (temp->next != NULL && temp->next->val != val) {
            temp = temp->next;
        }
        ListNode* dNode = temp->next;
        temp->next = temp->next->next;
        delete dNode;
        
        return head;
    }
};