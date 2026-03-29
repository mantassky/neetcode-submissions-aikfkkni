class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ROWS;
    int COLS;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        queue<pair<int, int>> atl;
        queue<pair<int, int>> pac;
        for (int r = 0; r < ROWS; r++) {
            atl.push({r, COLS-1});
            pac.push({r, 0});
        }
        for (int c = 0; c < COLS; c++) {
            atl.push({ROWS-1, c});
            pac.push({0, c});
        }

        vector<vector<int>> res;
        vector<vector<bool>> explorationAtl(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> explorationPac(ROWS, vector<bool>(COLS, false));

        checkOcean(atl, explorationAtl, heights);
        checkOcean(pac, explorationPac, heights);

        for (int r = 0; r < ROWS; r++)
            for (int c = 0; c < COLS; c++)
                if (explorationAtl[r][c] && explorationPac[r][c])
                    res.push_back({r, c});

        return res;
    }

    void checkOcean(
        queue<pair<int, int>>& q,
        vector<vector<bool>>& exploration,
        vector<vector<int>>& heights
    ) {
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> tile = q.front();
                q.pop();
                if (exploration[tile.first][tile.second]) continue;
                exploration[tile.first][tile.second] = true;

                for (int i = 0; i < 4; i++) {
                    int r = tile.first + dirs[i][0];
                    int c = tile.second + dirs[i][1];

                    if (
                        r < 0 ||
                        c < 0 ||
                        r >= ROWS ||
                        c >= COLS ||
                        heights[r][c] < heights[tile.first][tile.second] ||
                        exploration[r][c] == 1
                    ) continue;
                    q.push({r, c});
                }
            }
        }
    }
};
