class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++)
            for (int c = 0; c < board[0].size(); c++)
                if (exist(board, word, 0, {r, c})) return true;
            
        return false;
    }

    bool exist(vector<vector<char>>& board, string& word, int index, pair<int, int> pos) {
        if (index == word.size()) return true;

        if (pos.first < 0 || pos.second < 0 ||
            pos.first >= board.size() || pos.second >= board[0].size()
        ) return false;

        char tile = board[pos.first][pos.second];
        if (tile ==  '.' || word[index] != tile) return false;

        board[pos.first][pos.second] = '.';

        bool res = (
            exist(board, word, index+1, {pos.first, pos.second+1}) ||
            exist(board, word, index+1, {pos.first, pos.second-1}) ||
            exist(board, word, index+1, {pos.first+1, pos.second}) ||
            exist(board, word, index+1, {pos.first-1, pos.second})
        );
        
        board[pos.first][pos.second] = tile;
        return res;
    }
};
