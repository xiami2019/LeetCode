/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
方法1：k阶归并
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int listsLen = lists.size();
        if (listsLen == 0) return NULL;
        if (listsLen == 1) return lists[0];

        while (true) {
            int minNum = INT_MAX, index = -1;
            bool flag = true;
            for (int i = 0; i < listsLen; i++) {
                if (lists[i] == NULL) continue;
                if (lists[i]->val < minNum) {
                    minNum = lists[i]->val;
                    index = i;
                }
                flag = false;
            }
            if (flag) break;

            temp->next = lists[index];
            temp = temp->next;
            lists[index] = lists[index]->next;
            temp->next = NULL;;
        }
        temp = dummy->next;
        delete dummy;
        return temp;
    }
};

/*
方法二：使用优先队列优化方法一。
*/

// 自定义优先队列的排序函数

struct cmp{
    bool operator () (ListNode* a, ListNode* b){
        return a->val > b->val; // 从队头开始递增（即队头最小）
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int listsLen = lists.size();
        if (listsLen == 0) return NULL;
        if (listsLen == 1) return lists[0];
        priority_queue<ListNode*, vector<ListNode*>, cmp> waitForMerge;
        for (int i = 0; i < listsLen; i++) {
            if (lists[i] != NULL) waitForMerge.push(lists[i]);
        }

        while (!waitForMerge.empty()) {
            ListNode* minNum = waitForMerge.top();
            temp->next = minNum;
            temp = temp->next;
            minNum = minNum->next;
            temp->next = NULL;
            waitForMerge.pop();
            if (minNum != NULL) {
                waitForMerge.push(minNum);
            }
        }

        temp = dummy->next;
        delete dummy;
        return temp;
    }
};

/*
方法三：分治算法；
将k个链表两两配对，然后合并；
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int listsLen = lists.size();
        int interval = 1;
        
        while (interval < listsLen) {
            for (int i = 0; i < listsLen - interval; i += interval * 2) {
                lists[i] = this->merge2Lists(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }
        if (listsLen > 0) return lists[0];
        else return NULL;
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
            temp->next = NULL;
        }
        if (l1 == NULL) temp->next = l2;
        else temp->next = l1;
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};