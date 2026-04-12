class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> col(m, 1);

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                col[j] += col[j-1];

        return col[m-1];
    }
};
