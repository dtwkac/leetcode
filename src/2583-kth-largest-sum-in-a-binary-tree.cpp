/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) {
            return -1;
        }
        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>>
            min_heap;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            long long level_sum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                level_sum += q.front()->val;
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                q.pop();
            }
            if (min_heap.size() < k) {
                min_heap.push(level_sum);
            } else if (level_sum > min_heap.top()) {
                min_heap.pop();
                min_heap.push(level_sum);
            }
        }
        return min_heap.size() == k ? min_heap.top() : -1;
    }
};
