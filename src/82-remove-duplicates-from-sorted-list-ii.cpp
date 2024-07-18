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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode sentinel(-1, head), *prev = &sentinel, *curr = head;
        while (curr) {
            ListNode* post = curr->next;
            bool duplicated = false;
            while (post && post->val == curr->val) {
                duplicated = true;
                post = post->next;
            }
            if (duplicated) {
                prev->next = post;
                curr = post;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return sentinel.next;
    }
};
