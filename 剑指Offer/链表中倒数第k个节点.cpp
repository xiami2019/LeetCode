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
//法1存下所有指针；
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == NULL){
            return head;
        }
        vector<ListNode*> allPoints;
        while (head != NULL){
            allPoints.push_back(head);
            head = head->next;
        }

        return allPoints[allPoints.size() - k];
    }
};


class Solution {
public:
    //使用快慢指针，
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (k--){
            fast = fast->next;
        }
        while (fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};