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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> s;
        vector<int> v;
        ListNode* curr = head;
        s.push({-1, INT_MAX});
        int i = 0;
        while (curr) {
            v.push_back(0);
            while (curr->val > s.top().second) {
                v[s.top().first] = curr->val;
                s.pop();
            }
            s.push({i++, curr->val});
            curr = curr->next;
        }
        return v;
    }
};
