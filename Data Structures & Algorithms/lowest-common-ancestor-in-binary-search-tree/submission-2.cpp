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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        unordered_set<int> visited;
        while (temp != p) {
            int val = temp->val;
            visited.insert(val);
            
            if (val > p->val) temp = temp->left;
            else temp = temp->right;
        }
        visited.insert(temp->val);

        temp = root;
        TreeNode* latestMarked = root;
        while (temp != q) {
            int val = temp->val;
            if (visited.contains(val))
                latestMarked = temp;

            if (val > q->val) temp = temp->left;
            else temp = temp->right;
        }
        if (visited.contains(temp->val)) return temp;

        return latestMarked;
    }
};
