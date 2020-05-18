/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
归并排序：递归写法
分割cut环节：
找到当前链表中点，并从中点将链表断开（以便在下次递归cut时，链表片段拥有正确边界）；
1. 我们使用fast，slow快慢双指针法，奇数个节点找到中点，偶数个节点找到中心左边的节点。
2. 找到中点slow后，执行slow->next = None将链表切断。
3. 递归分割时，输入当前链表左端点head和中心节点slow的下一个节点tmp（因为链表是从slow
切断的）。
cut递归终止条件：当head->next == None时，说明只有一个节点了，直接返回此节点。
合并merge环节：
将两个排序链表合并，转化为一个排序链表。
1. 双指针法合并，建立辅助ListNode h作为头部。
2. 设置两个指针left，right分别指向两链表头部，比较两指针处节点。
3. 返回辅助ListNode h作为头部的下个节点h->next
4. 时间复杂度O(l+r), l, r分别代表两个链表长度。
*/
class Solution {
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* h = new ListNode(0);
        ListNode* res = h;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                h->next = list1;
                list1 = list1->next;
            }
            else {
                h->next = list2;
                list2 = list2->next;
            }
            h = h->next;
        }
        h->next = list1 != NULL ? list1 : list2;
        h = res;
        res = res->next;
        delete h;
        return res;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(temp);
        return merge(left, right);
    }
};


/*
归并排序：迭代写法
从底至顶直接合并
对于非递归的归并排序，需要使用迭代的方式替换cut环节：
1. cut环节本质上是通过二分法得到链表最小节点单元，再通过多轮合并得到排序结果。
2. 每一轮合并merge操作针对的单元都有固定长度intv，例如：第一轮合并时intv = 1，即将整个链表切分为多个长度
   为1的单元，并按顺序两两合并，合并完成的已排序单元长度为2.
   第二轮合并时intv=2，即将整个链表切分为多个长度为2的单元，并按顺序两两排序合并，合并完成已排序单元长度
   为4.
   以此类推，直到单元长度intv >= 链表长度，代表已经排序完成。
3. 根据以上推论，我们可以根据intv计算每个单元边界，并完成链表的每轮排序合并，例如：
   当intv = 1时，将链表第1和第2节点排序合并，第3和第4节点排序合并。
   当intv = 2时，将链表第1-2和第3-4节点排序合并，第5-6和第7-8节点排序合并。
   当intv = 4时，将链表第1-4和第5-8节点排序合并，第9-12,13-16节点排序合并

统计链表长度length，用于通过判断intv < length判定是否完成排序；
额外声明一个节点res，作为头部，后面连接整个链表，用于：
1. intv *= 2切换到下一轮合并时，可通过res->next找到链表头部；
2. 执行排序合并时，需要一个辅助节点作为头部，而res则作为链表头部排序合并时的辅助头部pre；后面的合并排序
   可以将上次合并排序的尾部tail用作辅助节点。

在每轮intv下的合并流程：
1. 根据intv找到合并单元1和单元2的头部h1，h2。由于链表长度可能不是2^n，需要考虑边界条件：
   在找h2的过程中，如果链表剩余元素个数少于intv，则无需合并环节，直接break，执行下一轮合并；
   若h2存在，但以h2为头部的剩余元素个数少于intv，也执行合并环节，h2单元的长度为c2 = intv-1.

2. 合并长度为c1，c2的h1，h2链表，其中：
   合并完成后，需要修改新的合并单元的尾部pre指针，指向下一个合并单元的头部h。
   （在寻找h1，h2环节中，h指针已经被移动到下一个单元头部）
   合并单元尾部同时也作为下次合并的辅助头部pre。
3. 当h == None，代表此轮intv合并完成，跳出。

每轮合并完成后将单元长度x2，切换到下轮合并：intv *= 2。
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* h = head;
        int intv = 1, length = 0;
        ListNode* res = new ListNode(0);
        res->next = head;
        while (h != NULL) {
            length++;
            h = h->next;
        }

        // merge the list in different intv.
        while (intv < length) {
            // 循环退出条件：intv < length，此时说明已经无法再进一步进行归并；

            ListNode* pre = res; // 使用一个辅助节点作为分段链表的头节点；
            h = res->next; // 正式开始分段；
            while (h != NULL) {
                // get the list heads 'h1', 'h2'.
                ListNode* h1 = h;
                int i = intv;
                while (i > 0 && h != NULL) {
                    h = h->next;
                    i--;
                }

                if (i > 0) break; // 说明第一段链表的长度不足intv，所以也就不存在h2了，此时已经到乐链表的末尾，不需要再归并了，可以直接退出；
                ListNode* h2 = h;
                i = intv;
                while (i > 0 && h != NULL) {
                    h = h->next;
                    i--;
                }
                int h1Len = intv, h2Len = intv - i;

                // merge the 'h1' and 'h2'
                while (h1Len > 0 && h2Len > 0) {
                    if (h1->val < h2->val) {
                        pre->next = h1;
                        h1 = h1->next;
                        h1Len--;
                    }
                    else {
                        pre->next = h2;
                        h2 = h2->next;
                        h2Len--;
                    }
                    pre = pre->next;
                }
                pre->next = h1Len > 0 ? h1 : h2;
                while (h1Len > 0 || h2Len > 0) {
                    pre = pre->next;
                    h1Len--;
                    h2Len--;
                }
                pre->next = h; // 切换到下一段的链表头；
            }
            intv *= 2; // 段长度倍增；
        }
        h = res;
        res = res->next;
        delete h;
        return res;
    }
};