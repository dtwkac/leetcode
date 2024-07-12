/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode sentinel(-1, head), *former = &sentinel, *curr = head;
        while (curr) {
            ListNode *pioneer = curr, *new_head = nullptr, *new_tail = nullptr;
            for (int i = 0; i < k; ++i) {
                if (!pioneer) {
                    return sentinel.next;
                }
                if (i == 0) {
                    new_tail = pioneer;
                }
                if (i == k - 1) {
                    new_head = pioneer;
                }
                pioneer = pioneer->next;
            }
            ListNode* prev = nullptr;
            for (int i = 0; i < k; ++i) {
                ListNode* post = curr->next;
                curr->next = prev;
                prev = curr;
                curr = post;
            }
            former->next = new_head;
            new_tail->next = curr;
            former = new_tail;
        }
        return sentinel.next;
    }
};
