/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (node->neighbors.empty()) return new Node(node->val);

        unordered_map<int, Node*> copies;
        return clone(node, copies);
    }

    Node* clone(Node* node, unordered_map<int, Node*>& copies) {
        if (copies.contains(node->val)) return copies[node->val];

        Node* copy = new Node(node->val);
        copies[node->val] = copy;

        for (Node* n: node->neighbors)
            copy->neighbors.push_back(clone(n, copies));

        return copy;
    }
};
