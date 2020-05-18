/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
法1：暴力；时间O（mn），空间O（1）
法2：哈希表存地址，以空间换时间（set或者map）；时间：O（m+n），空间O（1）；
法3：双指针（快慢指针）；
*/
class Solution {
public:
//先算出两个链表的长度，然后再快慢指针；
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int list1Len = 0, list2Len = 0;
        ListNode* temp = headA;
        while (temp != NULL){
            temp = temp->next;
            list1Len++;
        }
        temp = headB;
        while (temp != NULL){
            temp = temp->next;
            list2Len++;
        }

        //开始快慢指针
        if (list1Len > list2Len){
            int n = list1Len - list2Len;
            while (n--){
                headA = headA->next;
            }
        }
        else{
            int n = list2Len - list1Len;
            while (n--){
                headB = headB->next;
            }
        }

        while (headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};


class Solution {
public:
//双指针法；
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* list1 = headA;
        ListNode* list2 = headB;
        while (list1 != list2){
            if (list1 == NULL){
                list1 = headB;
            }
            else{
                list1 = list1->next;
            }

            if (list2 == NULL){
                list2 = headA;
            }
            else{
                list2 = list2->next;
            }
        }

        return list1;
    }
};