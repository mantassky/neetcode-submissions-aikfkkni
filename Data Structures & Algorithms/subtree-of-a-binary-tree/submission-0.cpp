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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return traverse(root, subRoot);
    }

    bool traverse(TreeNode* node, TreeNode* subRoot) {
        if (node == nullptr) return false;
        bool isSubtree = sameTree(node, subRoot);

        if (isSubtree)
            return true;
        else
            return traverse(node->left, subRoot) || traverse(node->right, subRoot);
    }

    bool sameTree(TreeNode* node, TreeNode* subNode) {
        if (!subNode && !node) return true;
        if ((!node && subNode) || (node && !subNode)) return false;

        return (
            node->val == subNode->val &&
            sameTree(node->left, subNode->left) &&
            sameTree(node->right, subNode->right)
        );
    }
};
