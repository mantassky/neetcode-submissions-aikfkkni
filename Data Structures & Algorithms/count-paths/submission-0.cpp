class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> col(m-1, 1);

        int cell;
        for (int i = 1; i < n; i++) {
            cell = 1;
            for (int j = 0; j < m-1; j++) {
                col[j] = cell+col[j];
                cell = col[j];
            }
        }

        return cell;
    }
};
