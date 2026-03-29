class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for (int row = 0; row < grid.size(); row++)
            for (int col = 0; col < grid[0].size(); col++)
                if (grid[row][col] == '1') {
                    exploreIsland(grid, row, col);
                    res++;
                }

        return res;
    }

    void exploreIsland(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        if (grid[row][col] == '0') return;

        grid[row][col] = '0';

        exploreIsland(grid, row, col+1);
        exploreIsland(grid, row+1, col);
        exploreIsland(grid, row, col-1);
        exploreIsland(grid, row-1, col);
    }
};
