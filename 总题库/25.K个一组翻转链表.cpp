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
        if (head == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *preNode = &dummy, *nextNode = preNode->next;
        int nodeNum = k;
        while (preNode != NULL) {
            nodeNum = k;
            while (nodeNum--) {
                if (nextNode == NULL) return dummy.next;
                nextNode = nextNode->next;
            }
            ListNode* iter;
            nodeNum = k;
            while (nodeNum--) {
                iter = preNode->next;
                preNode->next = preNode->next->next;
                iter->next = nextNode;
                nextNode = iter;
            }
            preNode->next = nextNode;
            nodeNum = k;
            while (nodeNum--) {
                preNode = preNode->next;
            }
            nextNode = preNode->next;
        }
        return dummy.next;
    }
};

// LeetCode题解
class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* preNode = new ListNode(0);
        preNode->next = head;
        ListNode* pre = preNode;

        while (head) {
            ListNode* tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return preNode->next;
                }
            }
            ListNode *nex = tail->next;
            // 翻转K个链表
            pair<ListNode*, ListNode*> result = myReverse(head, tail);
            head = result.first;
            tail = result.second;
            // 将翻转后的K个链表接在原链表上
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return preNode->next;
    }
};