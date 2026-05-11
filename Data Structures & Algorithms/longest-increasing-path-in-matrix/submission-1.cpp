class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> tab;
    int m, n;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        tab.resize(n, vector<int>(m, 0));

        int res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tab[i][j] == 0)
                    res = max(res, dfs(matrix, i, j));
            }
        }

        return res;
    }

    int dfs(vector<vector<int>> matrix, int x, int y) {
        if (tab[x][y] > 0) return tab[x][y];
        int val = matrix[x][y];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> ns;
        for (vector<int> dir: dirs) {
            int newX = dir[0] + x;
            int newY = dir[1] + y;
            if (
                newX < 0 ||
                newX >= n ||
                newY < 0 ||
                newY >= m ||
                matrix[newX][newY] <= val
            ) continue;

            ns.push({matrix[newX][newY], newX, newY});
        }


        int maxPath = 0;
        while (!ns.empty()) {
            vector<int> top = ns.top();
            ns.pop();
            maxPath = max(maxPath, dfs(matrix, top[1], top[2]));
        }

        tab[x][y] = maxPath + 1;
        return tab[x][y];
    }
};
