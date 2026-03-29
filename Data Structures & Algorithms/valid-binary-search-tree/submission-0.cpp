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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }

    bool isValidBST(TreeNode* node, int minLimit, int maxLimit) {
        if (!node) return true;

        return (
            minLimit < node->val && node->val < maxLimit &&
            isValidBST(node->left, minLimit, min(maxLimit, node->val)) &&
            isValidBST(node->right, max(minLimit, node->val), maxLimit)
        );
    }
};
