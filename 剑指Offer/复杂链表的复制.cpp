/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return head;

        Node newHead(0), *newIter = &newHead, *iter = head;
        while (iter) {
            Node* temp = iter->next;
            iter->next = new Node(iter->val);
            iter->next->next = temp;
            iter = temp;
        }

        iter = head;
        while (iter) {
            iter->next->random = iter->random ? iter->random->next : iter->random;
            iter = iter->next->next;
        }

        iter = head;
        while (iter) {
            newIter->next = iter->next;
            iter->next = iter->next->next;
            iter = iter->next;
            newIter = newIter->next;
        }
        return newHead.next;
    }
};