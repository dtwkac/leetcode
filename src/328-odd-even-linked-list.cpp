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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *first_even = head->next, *last_odd = nullptr,
                 *curr_odd = head, *curr_even = head->next, *next_odd = nullptr,
                 *next_even = nullptr;
        while (curr_odd) {
            if (curr_odd->next) {
                next_odd = curr_odd->next->next;
            } else {
                last_odd = curr_odd;
                break;
            }
            if (curr_even->next) {
                next_even = curr_even->next->next;
            } else {
                last_odd = curr_odd;
                break;
            }
            curr_odd->next = next_odd;
            curr_even->next = next_even;
            curr_odd = next_odd;
            curr_even = next_even;
        }
        last_odd->next = first_even;
        return head;
    }
};
