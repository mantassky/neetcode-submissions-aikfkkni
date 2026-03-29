class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        vector<pair<int, int>> queens;
        solveNQueens(n, 0, queens);
        return res;
    }

    void solveNQueens(int n, int row, vector<pair<int, int>>& queens) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));

            for (pair<int, int> pos: queens) {
                board[pos.first][pos.second] = 'Q';
            }
            
            res.push_back(board);
        }
        
        for (int col = 0; col < n; col++) {
            if (clash(row, col, queens)) continue;

            queens.push_back({row, col});
            solveNQueens(n, row+1, queens);
            queens.pop_back();
        }
    }

    bool clash(int row, int col, vector<pair<int, int>>& queens) {
        for (pair<int, int> pos: queens)
            if (clash({row, col}, pos)) return true;
        
        return false;
    }

    bool clash(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return true;
        if (a.second == b.second) return true;

        if (a.first - a.second == b.first - b.second) return true;
        if (a.first + a.second == b.first + b.second) return true;

        return false;
    }
};
