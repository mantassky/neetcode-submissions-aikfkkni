/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        height(root, res);
        return res;
    }

    int height(TreeNode* node, bool& res) {
        if (node == nullptr) return 0;

        int l = height(node->left, res);
        int r = height(node->right, res);

        if (abs(l - r) > 1) res = false;
        return 1 + max(l, r);
    }
};
