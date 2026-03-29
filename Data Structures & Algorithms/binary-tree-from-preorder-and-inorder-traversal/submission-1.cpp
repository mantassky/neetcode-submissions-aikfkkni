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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndexes;
        for (int i = 0; i < inorder.size(); i++)
            inorderIndexes[inorder[i]] = i;
        
        return buildTree(
            inorderIndexes,
            inorder,
            preorder,
            0,
            {0, inorder.size()}
        );
    }

    TreeNode* buildTree(
        unordered_map<int, int>& inorderIndexes,
        vector<int>& inorder,
        vector<int>& preorder,
        int preorderStart,
        pair<int, int> inorderRange
    ) {
        if (inorderRange.first >= inorder.size() || inorderRange.first < 0) {
            cout<<"inorderRange.first not in arr: "<<inorderRange.first <<endl;
            return nullptr;
        }
        

        if (inorderRange.first == inorderRange.second)
            return nullptr;
        if (inorderRange.first + 1 >= inorderRange.second)
            return new TreeNode(inorder[inorderRange.first]);
        
        if (preorder.size() <= preorderStart || preorderStart < 0) {
            cout<<"preorder start not in arr: "<<preorderStart <<endl;
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[preorderStart]);

        if (!inorderIndexes.contains(node->val)) {
            cout<<"nodeval not in map: "<<node->val<<endl;
            return nullptr;
        }
        int pos = inorderIndexes[node->val];

        node->left = buildTree(
            inorderIndexes,
            inorder,
            preorder,
            preorderStart+1,
            {inorderRange.first, pos}
        );

        node->right = buildTree(
            inorderIndexes,
            inorder,
            preorder,
            preorderStart + 1 + pos - inorderRange.first,
            {pos+1, inorderRange.second}
        );

        return node;
    }
};
