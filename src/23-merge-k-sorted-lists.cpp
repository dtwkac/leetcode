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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode sentinel(-1), *curr = &sentinel;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1 ? list1 : list2;
        return sentinel.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        if (low == high) {
            return lists[low];
        }
        int mid = low + (high - low) / 2;
        return mergeTwoLists(mergeKLists(lists, low, mid),
                             mergeKLists(lists, mid + 1, high));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
};
