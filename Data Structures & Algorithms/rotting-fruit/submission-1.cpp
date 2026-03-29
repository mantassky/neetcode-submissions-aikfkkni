class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ROWS;
    int COLS;

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> toRot;
        ROWS = grid.size();
        COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++)
            for  (int c = 0; c < COLS; c++)
                if (grid[r][c] == 2)
                    toRot.push({r, c});

        int time = -1;
        while (!toRot.empty()) {
            int size = toRot.size();
            time++;

            for (int i = 0; i < size; i++) {
                pair<int, int> front = toRot.front();
                toRot.pop();
                grid[front.first][front.second] = 2;

                for (int j = 0; j < 4; j++) {
                    int r = dirs[j][0] + front.first;
                    int c = dirs[j][1] + front.second;

                    if (
                        r < 0 ||
                        c < 0 ||
                        r >= ROWS ||
                        c >= COLS ||
                        grid[r][c] != 1
                    ) continue;
                    toRot.push({r, c});
                }
            }
        }

        for (int r = 0; r < ROWS; r++)
            for  (int c = 0; c < COLS; c++)
                if (grid[r][c] == 1)
                    return -1;
        
        return max(0, time);
    }
};
