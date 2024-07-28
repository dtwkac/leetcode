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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        function<int(int, int)> gcd = [&gcd](int a, int b) -> int {
            if (a > b) {
                return gcd(b, a);
            }
            while (a != 0) {
                int temp = a;
                a = b % a;
                b = temp;
            }
            return b;
        };
        if (!head || !head->next) {
            return head;
        }
        ListNode* curr = head;
        while (curr && curr->next) {
            ListNode* post = curr->next;
            curr->next = new ListNode(gcd(curr->val, curr->next->val), post);
            curr = post;
        }
        return head;
    }
};
