class PrefixTree {
public:
    struct TrieNode {
        bool isWord;
        unordered_map<char, TrieNode*> children;
        TrieNode(): isWord(false) {};
        TrieNode(bool val): isWord(val) {};
    };

    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;

        for (char c: word) {
            if (!temp->children.contains(c))
                temp->children[c] = new TrieNode();
            temp = temp->children[c];
        }

        temp->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;

        for (char c: word) {
            if (!temp->children.contains(c))
                return false;
            temp = temp->children[c];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;

        for (char c: prefix) {
            if (!temp->children.contains(c))
                return false;
            temp = temp->children[c];
        }
        return true;
    }
};
