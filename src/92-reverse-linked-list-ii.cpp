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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;
        ListNode *curr = head, *prev = nullptr;
        ListNode *left_tail = nullptr, *right_head = nullptr,
                 *rev_head = nullptr, *rev_tail = nullptr;
        while (curr) {
            if (i == left - 1) {
                left_tail = prev = curr;
                curr = curr->next;
            } else if (i >= left && i <= right) {
                if (i == left) {
                    rev_tail = curr;
                }
                if (i == right) {
                    rev_head = curr;
                    right_head = curr->next;
                }
                ListNode* post = curr->next;
                curr->next = prev;
                prev = curr;
                curr = post;
            } else {
                curr = curr->next;
            }
            ++i;
        }
        rev_tail->next = right_head;
        if (left_tail) {
            left_tail->next = rev_head;
            return head;
        } else {
            return rev_head;
        }
    }
};
