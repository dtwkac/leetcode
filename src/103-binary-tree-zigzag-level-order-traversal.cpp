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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                if (curr) {
                    v.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
                q.pop();
            }
            if (flag) {
                reverse(v.begin(), v.end());
            }
            if (!v.empty()) {
                vv.push_back(v);
            }
            flag = !flag;
        }
        return vv;
    }
};
