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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        bool leftChild = root->left != nullptr;
        bool rightChild = root->right != nullptr;

        return (
            encodeVal(root->val) +
            encodeChildren(root) +
            serialize(root->left) +
            serialize(root->right)
        );
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        cout<<data;
        return deserialize(data, i);
    }

    TreeNode* deserialize(string data, int& i) {
        if (i >= data.size()) return nullptr;

        string num_str = data.substr(i, 4);
        int val = decodeVal(num_str);
        bool leftChild = decodeChild(data[i+4]);
        bool rightChild = decodeChild(data[i+5]);

        TreeNode* node = new TreeNode(val);

        i += 6;
        node->left = leftChild ? deserialize(data, i) : nullptr;
        node->right = rightChild ? deserialize(data, i) : nullptr;

        return node;
    }

    string encodeVal(int num) {
        return to_string(num+2000);
    }

    int decodeVal(string str) {
        return stoi(str) - 2000;
    }

    string encodeChildren(TreeNode* node) {
        bool leftChild = node->left != nullptr;
        bool rightChild = node->right != nullptr;

        return string(leftChild?"o":"x") + string(rightChild?"o":"x");
    }

    bool decodeChild(char c) {
        return c == 'o';
    }
};
