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
    int diameterOfBinaryTree(TreeNode* root) {
        return (depthDiameter(root)).second;
    }

    pair<int, int> depthDiameter(TreeNode* node) {
        pair<int, int> l = (node->left != nullptr) ? depthDiameter(node->left) : pair<int,int>{0, 0};
        pair<int, int> r = (node->right != nullptr) ? depthDiameter(node->right) : pair<int,int>{0, 0};
        int depth = ((node->left != nullptr || node->right != nullptr) ? 1 : 0) + max(l.first, r.first);
        int diameter =
            (node->left != nullptr ? l.first + 1 : 0) + 
            (node->right != nullptr ? r.first + 1 : 0);

        cout<<node->val<<": depth, diameter: "<<depth<<" "<<diameter<<endl;
        return {depth, max(diameter, max(l.second, r.second))};
    }
};
