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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }

    int maxPathSum(TreeNode* node, int& res) {
        if (!node) return 0;

        int maxLeft = maxPathSum(node->left, res);
        int maxRight = maxPathSum(node->right, res);

        res = max(res, node->val + maxLeft + maxRight);
        int maxContinuous = max(node->val + maxLeft, node->val + maxRight);
        res = max(res, maxContinuous);

        return max(0, max(node->val + maxLeft, node->val + maxRight));
    }
};
