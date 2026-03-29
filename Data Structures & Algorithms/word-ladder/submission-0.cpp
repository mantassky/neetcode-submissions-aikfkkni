class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int m = wordList[0].size();
        unordered_map<string, vector<string>> adj;

        wordList.push_back(beginWord);
        for (string word: wordList) adj[word] = {};
        
        for (string word: wordList)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < 26; j++) {
                    char c = 'a' + j;
                    string adjWord = word;
                    adjWord[i] = c;

                    if (adjWord != word && adj.contains(adjWord))
                        adj[word].push_back(adjWord);
                }

        //BFS
        queue<string> q({beginWord});
        unordered_set<string> visited;
        int count = 0;
        while(!q.empty()) {
            count++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string top = q.front();
                q.pop();
                if (top == endWord) return count;
                visited.insert(top);

                for (string n: adj[top]) {
                    if (visited.contains(n)) continue;

                    q.push(n);
                }
            }
        }

        return 0;
    }
};
