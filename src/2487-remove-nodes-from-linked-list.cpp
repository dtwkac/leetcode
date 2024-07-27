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
        ListNode sentinel(-1, nullptr), *prev = &sentinel, *curr = head;
        vector<ListNode*> v;
        while (curr) {
            while (!v.empty() && curr->val > v[v.size() - 1]->val) {
                v.pop_back();
            }
            v.push_back(curr);
            curr = curr->next;
        }
        for (ListNode* i : v) {
            prev->next = i;
            prev = prev->next;
        }
        return sentinel.next;
    }
};
