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
    vector<int> reverseBookList(ListNode* head) {
        stack<int> s;
        while (head) {
            s.push(head->val);
            head = head->next;
        }
        vector<int> v;
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};
