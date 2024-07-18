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
        ListNode *former_tail = nullptr, *successor_head = nullptr,
                 *new_head = nullptr, *new_tail = nullptr;
        ListNode *prev = nullptr, *curr = head;
        for (int i = 1; i <= right; ++i) {
            if (i == left) {
                new_tail = curr;
                former_tail = prev;
            }
            if (i == right) {
                new_head = curr;
                successor_head = curr->next;
            }
            prev = curr;
            curr = curr->next;
        }
        curr = new_tail;
        prev = nullptr;
        for (int i = left; i <= right; ++i) {
            ListNode* post = curr->next;
            curr->next = prev;
            prev = curr;
            curr = post;
        }
        new_tail->next = successor_head;
        if (new_tail == head) {
            return new_head;
        } else {
            former_tail->next = new_head;
            return head;
        }
    }
};
