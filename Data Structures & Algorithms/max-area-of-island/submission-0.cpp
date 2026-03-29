class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        for (int r = 0; r < grid.size(); r++)
            for (int c = 0; c < grid[0].size(); c++)
                if (grid[r][c] == 1)
                    res = max(res, exploreIsland(grid, r, c));
        
        return res;
    }

    int exploreIsland(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return 0;
        if (grid[r][c] == 0) return 0;

        grid[r][c] = 0;

        return (1 +
            exploreIsland(grid, r, c+1) +
            exploreIsland(grid, r+1, c) +
            exploreIsland(grid, r, c-1) +
            exploreIsland(grid, r-1, c)
        );
    }
};
