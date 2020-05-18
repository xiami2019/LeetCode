/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//头插法;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode* p = head->next;
        head->next = NULL; //断尾
        ListNode* q = NULL;
        while (p != NULL){ //指针操作一定要注意顺序
            q = p;
            p = p->next;
            q->next = head;
            head = q;
        }

        return head;
    }
};