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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> s;
        ListNode sentinel(-1, nullptr), *prev = &sentinel, *curr = head;
        while (curr) {
            s.push(curr);
            curr = curr->next;
        }
        while (!s.empty()) {
            if (!prev->next) {
                prev->next = s.top();
            } else {
                curr = prev->next;
                if (s.top()->val >= curr->val) {
                    prev->next = s.top();
                    prev->next->next = curr;
                }
            }
            s.pop();
        }
        return sentinel.next;
    }
};
