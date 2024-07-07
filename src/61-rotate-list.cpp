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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *curr = head, *last = nullptr;
        int size = 0;
        while (curr) {
            ++size;
            last = curr;
            curr = curr->next;
        }
        if (size == 0 || size == 1) {
            return head;
        }
        k %= size;
        if (k == 0) {
            return head;
        }
        curr = head;
        for (int i = 0; i < k; ++i) {
            curr = curr->next;
        }
        ListNode *target = head, *prev = nullptr;
        while (curr) {
            prev = target;
            curr = curr->next;
            target = target->next;
        }
        prev->next = nullptr;
        last->next = head;
        return target;
    }
};
