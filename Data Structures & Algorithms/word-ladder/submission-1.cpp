class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int m = wordList[0].size();
        unordered_set<string> words(wordList.begin(), wordList.end());
        words.insert(beginWord);

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
                
                for (int i = 0; i < m; i++)
                    for (char c = 'a'; c <= 'z'; c += 1) {
                        string adjWord = top;
                        adjWord[i] = c;

                        if (adjWord != top && words.contains(adjWord) && !visited.contains(adjWord))
                            q.push(adjWord);
                    }
            }
        }

        return 0;
    }
};
