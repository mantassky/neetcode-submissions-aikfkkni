class Solution {
public:
    unordered_set<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                for (string word: words) {
                    if (res.contains(word)) continue;

                    findWord(board, word, {row, col}, 0);
                }
            }
        }
        vector<string> ress;
        for (string word: this->res)
            ress.push_back(word);

        return ress;
    }

    void findWord(
        vector<vector<char>>& board,
        string& word,
        pair<int, int> pos,
        int index
) {
        if (pos.first < 0 ||
            pos.first >= board.size() ||
            pos.second < 0 ||
            pos.second >= board[0].size()
        ) return;

        char val = board[pos.first][pos.second];
        
        if (word[index] != val) return;

        if (index == word.size() - 1) {
            (this->res).insert(word);
            return;
        }

        board[pos.first][pos.second] = '.';

        findWord(board, word, {pos.first+1, pos.second}, index+1);
        findWord(board, word, {pos.first-1, pos.second}, index+1);
        findWord(board, word, {pos.first, pos.second+1}, index+1);
        findWord(board, word, {pos.first, pos.second-1}, index+1);

        board[pos.first][pos.second] = val;
    }
};
