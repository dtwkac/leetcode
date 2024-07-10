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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        for (int i = 0; i < n; ++i) {
            curr = curr->next;
        }
        ListNode *target = head, *prev_target = nullptr;
        while (curr) {
            prev_target = target;
            target = target->next;
            curr = curr->next;
        }
        if (target == head) {
            return head->next;
        }
        prev_target->next = target->next;
        return head;
    }
};
