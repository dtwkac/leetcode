/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vv;
        queue<Node*> q;
        if (!root) {
            return vv;
        }
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v(size);
            for (int i = 0; i < size; ++i) {
                Node* root = q.front();
                v[i] = root->val;
                for (Node* n : root->children) {
                    if (n) {
                        q.push(n);
                    }
                }
                q.pop();
            }
            vv.push_back(v);
        }
        return vv;
    }
};
