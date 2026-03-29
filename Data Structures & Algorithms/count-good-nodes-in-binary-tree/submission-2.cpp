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
    int goodNodes(TreeNode* root) {
        return countGood(root, INT_MIN);
    }

    int countGood(TreeNode* node, int maxInPath) {
        if (!node) return 0;

        return (
            countGood(node->left, max(maxInPath, node->val)) +
            countGood(node->right, max(maxInPath, node->val)) +
            (node->val >= maxInPath)
        );
    }
};
