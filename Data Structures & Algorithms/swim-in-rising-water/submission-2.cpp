class Solution {
public:
    vector<int> parent;
    vector<int> size;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int find_set(int a) {
        if (parent[a] == -1) return -1;
        if (parent[a] == a) return a;
        parent[a] = find_set(parent[a]);
        return parent[a];
    }

    void make_set(int a) {
        parent[a] = a;
        size[a] = 1;
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == -1 || b == -1 || a == b) return;

        if (size[a] < size[b])
            swap(a, b);
        
        parent[b] = a;
        size[a] += size[b];
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        parent.resize(n*n, -1);
        size.resize(n*n, -1);
        int tlVal = grid[0][0];
        int brVal = grid[n-1][n-1];

        vector<pair<int, int>> coords(n*n);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int val = grid[r][c];
                coords[val] = {r, c};
            }
        }

        int level = 0;
        while (level <= max(tlVal, brVal) || find_set(tlVal) != find_set(brVal)) {
            make_set(level);
            auto [r, c] = coords[level];
            for (pair<int, int> dir: dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                union_sets(grid[nr][nc], level);
            }

            // cout<<"level, set: "<<level<<", "<<find_set(level)<<endl;
            // for(int i = 0; i < n*n; i++) cout<<i<<": "<<parent[i]<<endl;
            level++;
        }

        return level-1;
    }
};
