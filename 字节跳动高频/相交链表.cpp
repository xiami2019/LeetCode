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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        if (headA == headB) return headA; // 判断特殊情况，只有一个结点（两个链表交于一个点）
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (1) {
            tempA = tempA->next;
            tempB = tempB->next;
            if (tempA == NULL && tempB == NULL) return NULL; // 链表没有交点
            if (tempA == NULL) tempA = headB; // 头尾相接
            if (tempB == NULL) tempB = headA; // 头尾相接
            if (tempA == tempB) return tempA;
        }
    }
};