class WordDictionary {
public:
    struct TrieNode {
        bool isWord;
        unordered_map<char, TrieNode*> children;
        TrieNode(): isWord(false) {};
        TrieNode(bool val): isWord(val) {};
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;

        for (char c: word) {
            if (!temp->children.contains(c))
                temp->children[c] = new TrieNode();
            temp = temp->children[c];
        }

        temp->isWord = true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }

    bool search(string word, int pos, TrieNode* node) {
        if (pos == word.size()) {
            if (node->isWord) return true;
            return false;
        }

        char c = word[pos];

        if (c != '.') {
            if (!node->children.contains(c)) return false;
            return search(word, pos+1, node->children[c]);
        }

        for (auto child: (node->children))
            if (search(word, pos+1, child.second)) return true;

        return false;
    }
};
