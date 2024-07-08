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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            vector<int> v;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* t = q.front();
                v.push_back(t->val);
                q.pop();
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
            vv.push_back(v);
        }
        reverse(vv.begin(), vv.end());
        return vv;
    }
};
