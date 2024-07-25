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
    ListNode* partition(ListNode* head, int x) {
        ListNode sentinel_small(-1), sentinel_large(-1),
            *head_small = &sentinel_small, *head_large = &sentinel_large,
            *curr = head;
        while (curr) {
            ListNode* post = curr->next;
            if (curr->val < x) {
                head_small->next = curr;
                head_small = curr;
                head_small->next = nullptr;
            } else {
                head_large->next = curr;
                head_large = curr;
                head_large->next = nullptr;
            }
            curr = post;
        }
        head_small->next = sentinel_large.next;
        return sentinel_small.next;
    }
};
