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
        if (head == NULL) return NULL;
        Node* curNode = head;
        while (curNode != NULL) {
            Node *temp = curNode->next;
            curNode->next = new Node(curNode->val);
            curNode->next->next = temp;
            curNode->next->random = curNode->random;
            curNode = temp;
        }

        curNode = head->next;
        while (1) {
            curNode->random = curNode->random ? curNode->random->next : NULL;
            if (curNode->next == NULL) break;
            curNode = curNode->next->next;
        }

        Node* newHead = head->next, *iter = newHead;
        curNode = head;
        while (curNode != NULL) {
            curNode->next = curNode->next->next;
            curNode = curNode->next;
            if (iter->next != NULL) {
                iter->next = iter->next->next;
                iter = iter->next;
            }
        }
        return newHead;
    }
};