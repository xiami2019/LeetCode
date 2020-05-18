#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
//方法1: 模拟;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int boost = 0, current = 0;
        vector<int> l1_v, l2_v;
        ListNode* head = NULL;
        ListNode* temp = l1;
        while(temp != NULL){
            l1_v.push_back(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while(temp != NULL){
            l2_v.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        for(int i = 0; i < l1_v.size() || i < l2_v.size(); i++){
            if(i < l1_v.size() && i < l2_v.size()){
                current = (l1_v[i] + l2_v[i] + boost) % 10;
                boost = (l1_v[i] + l2_v[i] + boost) / 10;
            }
            else if(i < l1_v.size() && i >= l2_v.size()){
                current = (l1_v[i] + boost) % 10;
                boost = (l1_v[i] + boost) / 10;
            }
            else if(i >= l1_v.size() && i < l2_v.size()){
                current = (l2_v[i] + boost) % 10;
                boost = (l2_v[i] + boost) / 10;
            }
            if(head == NULL){
                head = new ListNode(current);
                temp = head;
                continue;
            }
            temp->next = new ListNode(current);
            temp = temp->next;
        }
        if(boost != 0){
            temp->next = new ListNode(boost);
        }
        return head;
    }
};

//方法2: 使用队列;

int main()
{

}