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
    int kth = 0;

    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        inOrder(root, res, k);
        return res;
    }

    void inOrder(TreeNode* node, int& res, int k) {
        if (!node || res != -1) return;
        
        inOrder(node->left, res, k);
        kth++;
        if (kth == k) res = node->val;
        inOrder(node->right, res, k);
    }
};
