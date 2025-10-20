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
        ListNode sentinel(-1, head);
        ListNode* tail = head;
        for (int i = 0; i < n; ++i) {
            tail = tail->next;
        }
        ListNode *curr = head, *prev = &sentinel;
        while (tail) {
            prev = curr;
            curr = curr->next;
            tail = tail->next;
        }
        prev->next = curr->next;
        return sentinel.next;
    }
};
