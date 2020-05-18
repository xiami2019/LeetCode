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
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        stack<int> temp;
        while (head != NULL){
            temp.push(head->val);
            head = head->next;
        }

        while (!temp.empty()){
            result.push_back(temp.top());
            temp.pop();
        }
        return result;
    }
};