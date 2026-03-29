class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int r = 0; r < grid.size(); r++)
            for (int c = 0; c < grid[0].size(); c++)
                if (grid[r][c] == 0)
                    bfs(grid, r, c);
    }

    void bfs(vector<vector<int>>& grid, int r, int c) {
        vector<vector<bool>> explored(grid.size(), vector<bool>(grid[0].size(), false));

        queue<pair<int, int>> visits({{r, c}});

        int dist = 0;
        while (!visits.empty()) {
            int count = visits.size();
            for (int i = 0; i < count; i++) {
                pair<int, int> visit = visits.front();
                visits.pop();
                grid[visit.first][visit.second] = min(grid[visit.first][visit.second], dist);
                explored[visit.first][visit.second] = true;

                for (int i = 0; i < 4;i++) {
                    int nr = dirs[i][0] + visit.first;
                    int nc = dirs[i][1] + visit.second;
                    if (
                        nr < 0 ||
                        nc < 0 ||
                        nr >= grid.size() ||
                        nc >= grid[0].size() ||
                        grid[nr][nc] == -1 ||
                        explored[nr][nc]
                    ) continue;
                    visits.push({nr, nc});
                }
            }
            dist++;
        }
    }
};
