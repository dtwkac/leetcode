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
    ListNode* swapPairs(ListNode* head) {
        ListNode sentinel(-1, head), *prev = &sentinel, *curr = head;
        while (curr && curr->next) {
            prev->next = curr->next;
            ListNode* post = curr->next->next;
            curr->next->next = curr;
            curr->next = post;
            prev = curr;
            curr = post;
        }
        return sentinel.next;
    }
};
