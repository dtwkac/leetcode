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
        ListNode sentinel(-1, head), *prev = &sentinel, *target = head,
                                     *curr = head;
        for (int i = 0; i < n; ++i) {
            curr = curr->next;
        }
        while (curr) {
            curr = curr->next;
            target = target->next;
            prev = prev->next;
        }
        if (target == head) {
            return head->next;
        }
        prev->next = target->next;
        return head;
    }
};
