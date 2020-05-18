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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL){
            fast = fast->next;
            fast = fast->next;
            ListNode* temp1 = slow->next;
            ListNode* temp2 = temp1->next;
            temp1->next = fast;
            temp2->next = temp1;
            slow->next = temp2;
            slow = slow->next;
            slow = slow->next;
        }
        fast = dummy->next;
        delete dummy;
        return fast;
    }
};

/*
LeetCode递归写法
算法：
1. 从链表的头节点head开始递归；
2. 每次递归都负责交换一对节点。由firstNode和secondNode表示要交换的两个节点；
3. 下一次递归则是传递的是下一对需要交换的节点。若链表中还有节点，则继续递归；
4. 交换了两个节点以后，返回secondNode，因为它是交换后的新头；
5. 在所有节点交换完成以后，我们返回交换后的头，实际上是原始链表的第二个节点；
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If the list has no node or has only one node left.
        if (head == NULL || head->next == NULL) return head;
        
        // Nodes to be swapped.
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;
    
        // Swapping
        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;

        // Now the head is the second node
        return secondNode;
    }
};

/*
LeetCode迭代写法
我们把链表分为两部分，即奇数节点为一部分，偶数节点为一部分，A指的是交换节点中的前面的节点，
B指的是要交换节点中的后面的节点。在完成它们的交换后，我们还得用prevNode记录A的前驱结点。
算法：
1. firstNode（即A）和secondNode（即B）分别遍历偶数节点和奇数节点，即两步看作一步。
2. 交换两个节点：
3. preNode->next指向交换后的头。
4. 迭代完成后得到最终的结果。
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prevNode = dummy;

        while ((head != NULL) && (head->next != NULL)) {
            // Nodes to be swapped
            ListNode* firstNode = head;
            ListNode* secondNode = head->next;

            // Swapping
            prevNode->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            // Reinitializing the head and prevNode for next swap
            prevNode = firstNode;
            head = firstNode->next;
        }
        prevNode = dummy->next;
        delete dummy;
        return prevNode;
    }
};