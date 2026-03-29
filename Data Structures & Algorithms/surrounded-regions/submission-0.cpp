class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ROWS;
    int COLS;

    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            qPush(board, q, r, 0);
            qPush(board, q, r, COLS-1);
        }
        for (int c = 1; c < COLS-1; c++) {
            qPush(board, q, 0, c);
            qPush(board, q, ROWS-1, c);
        }

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> tile = q.front();
                q.pop();
                board[tile.first][tile.second] = 'G';

                for (int i = 0; i < 4; i++) {
                    int r = dirs[i][0] + tile.first;
                    int c = dirs[i][1] + tile.second;

                    if (
                        r < 0 ||
                        c < 0 ||
                        r >= ROWS ||
                        c >= COLS ||
                        board[r][c] != 'O'
                    ) continue;
                    q.push({r, c});
                }
            }
        }

        for (int r = 0; r < ROWS; r++)
            for (int c = 0; c <COLS; c++)
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                else if (board[r][c] == 'G')
                    board[r][c] = 'O';
    }

    void qPush(vector<vector<char>>& board, queue<pair<int, int>>& q, int r, int c) {
        if (board[r][c] == 'O') q.push({r, c});
    }
};
