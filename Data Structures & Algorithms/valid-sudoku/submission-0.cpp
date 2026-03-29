class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {{false}};
        bool cols[9][9] = {{false}};
        bool sqrs[9][9] = {{false}};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '1';

                if (rows[i][num] == true) return false;
                rows[i][num] = true;

                if (cols[j][num] == true) return false;
                cols[j][num] = true;

                int sqr =  3*(i/3) + j/3;
                if (sqrs[sqr][num] == true) return false;
                sqrs[sqr][num] = true;
            }
        }

        return true;
    }
};
