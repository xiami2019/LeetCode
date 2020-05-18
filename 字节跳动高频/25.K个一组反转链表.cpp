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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head; // 用来指向一个分组的末尾（下一分组的头结点）
        ListNode tempNode(0); // 临时结点，作为head结点的前驱结点
        tempNode.next = head; 
        ListNode* preNode = &tempNode; // 用来指向每个分组的前一个结点
        int index = 0; // 统计个数，用来分组
        while (tail != NULL) {
            tail = tail->next;
            index++;
            if (index == k){ // 已经够了k个结点，开始进行翻转
                index = 0;
                ListNode* nextGroup = tail; // 保存下一组的开始结点
                while (preNode->next != nextGroup){ // 使用fast指针和slow指针进行翻转
                    ListNode* temp = preNode->next;
                    preNode->next = preNode->next->next;
                    temp->next = tail;
                    tail = temp;
                }
                preNode->next = tail; // 前一个结点的next指针指向这k个结点里新的头结点
                tail = nextGroup; // 将fast和slow指针置于下一组开始的位置，准备新一组的翻转
                for (int i = 0; i < k; i++){
                    preNode = preNode->next; // 将preNode指针更新到新一组的前一个结点
                }
            }
        }
        return tempNode.next;
    }
};