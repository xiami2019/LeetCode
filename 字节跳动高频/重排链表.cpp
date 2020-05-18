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
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        stack<ListNode*> s;
        ListNode* temp = head;
        while (temp != NULL) {
            s.push(temp);
            temp = temp->next;
        }
        temp = head;
        while (temp != s.top() && temp->next != s.top()) {
            ListNode* nexttemp = temp->next;
            ListNode* tail = s.top();
            s.pop();
            s.top()->next = NULL;
            tail->next = nexttemp;
            temp->next = tail;
            temp = temp->next->next;
        }
    }
};

/*
方法二：递归
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }

        int len = 0;
        ListNode* h = head;
        // 求出节点数
        while (h != NULL) {
            len++;
            h = h->next;
        }

        reorderListHelper(head, len);
    }

private:
    ListNode* reorderListHelper(ListNode* head, int len) {
        if (len == 1) {
            ListNode* outTail = head->next;
            head->next = NULL;
            return outTail;
        }

        if (len == 2) {
            ListNode* outTail = head->next->next;
            head->next->next = NULL;
            return outTail;
        }

        // 得到对应的尾结点，并且将头结点和尾结点之间的链表通过递归处理
        ListNode* tail = reorderListHelper(head->next, len - 2);
        ListNode* subHead = head->next; // 中间链表的头结点
        head->next = tail;
        ListNode* outTail = tail->next; // 上一层head对应的tail
        tail->next = subHead;
        return outTail;
    }
};

/*
方法三：利用一头一尾取元素的特性
主要分为三步：
1. 将链表平均分成两半；
2. 将第二个链表逆序；
3. 依次连接两个链表；
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = head->next;
        head->next = NULL;
        while (temp != NULL) {
            ListNode* newHead = temp;
            temp = temp->next;
            newHead->next = head;
            head = newHead;
        }
        return head;
    }

public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        int len = 0;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            len++;
        }
        ListNode* temp = slow;
        slow = slow->next;
        temp->next = NULL;
        if (fast == NULL) {
            len--;
        }
        slow = reverseList(slow);
        while (len--) {
            ListNode* nextNode = head->next;
            head->next = slow;
            slow = slow->next;
            head->next->next = nextNode;
            head = nextNode;
        }
    }
};
