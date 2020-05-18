/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
法一：顺序合并：
用一个变量ans来维护以及合并的链表，第i次循环把第i个链表和ans合并，答案保存到ans中
时间复杂度：O(k^2n)
空间复杂度：O(1)
*/
class Solution {
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       ListNode *ans = NULL;
       for (int i = 0; i < lists.size(); i++) {
           ans = mergeTwoLists(ans, lists[i]);
       }
       return ans;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
法二：分治合并：
用分治的方法进行合并
将k个链表配对并将同一对中的链表合并；
第一轮合并以后，k个链表被合并成了k/2个链表，平均长度为2n/k, 然后是k/4个链表，k/8个链表等等；
重复这一过程，直到最终得到有序链表。
时间复杂度：O(kn * logk);
空间复杂度：O(logk);
*/
class Solution {
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = aPtr ? aPtr : bPtr;
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
        return merge(lists, 0, lists.size() - 1);
    }
};

/*
方法三：使用优先队列合并
需要维护当前每个链表没有被合并的元素的最前面一个，k个链表就最多有k个满足这样条件的元素，每次在这些元素里面选取val属性
最小的元素合并到答案中。在选取最小元素的时候，我们可以用优先队列来优化这个过程。
*/
class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }

        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};