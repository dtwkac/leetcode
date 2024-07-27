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
        ListNode sentinel(-1), *prev = &sentinel, *curr = head;
        stack<ListNode*> s;
        while (curr) {
            while (!s.empty() && curr->val > s.top()->val) {
                s.pop();
            }
            s.push(curr);
            curr = curr->next;
        }
        while (!s.empty()) {
            curr = prev->next;
            prev->next = s.top();
            s.top()->next = curr;
            s.pop();
        }
        return sentinel.next;
    }
};
