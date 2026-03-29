class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int m = wordList[0].size();
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.contains(endWord) || beginWord == endWord) return 0;
        int res = 0;
        queue<string> q;
        q.push(beginWord);

        while(!q.empty()) {
            res++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                string node = q.front();
                q.pop();
                if (node == endWord) return res;
                
                for (int j = 0; j < m; j++) {
                    char original = node[j];
                    for (char c = 'a'; c <= 'z'; c ++) {
                        if (c == original) continue;
                        node[j] = c;
                        if (words.contains(node)) {
                            q.push(node);
                            words.erase(node);
                        }
                    }
                    node[j] = original;
                }
            }
        }

        return 0;
    }
};
