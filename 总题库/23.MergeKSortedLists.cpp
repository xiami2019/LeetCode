/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 分治
class Solution {
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head;
        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            }
            else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = (a ? a : b);
        return head.next;
    }

    ListNode* merge(vector<ListNode*> &lists, int left, int right) {
        if (left == right) return lists[left];
        if (left > right) return NULL;
        int mid = (left + right) >> 1;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        int len = lists.size();
        for (int interval = 1; interval < len; interval *= 2) {
            for (int i = interval; i < len; i += 2 * interval) {
                lists[i - interval] = mergeTwoLists(lists[i - interval], lists[i]);
                lists[i] = NULL;
            }
        }
        return lists[0];
    }
};