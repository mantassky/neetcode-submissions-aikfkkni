class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() < s2.size()) swap(s1, s2);
        int n = s1.size();
        int m = s2.size();
        if (n+m != s3.size()) return false;

        vector<vector<bool>> tab(n+1, vector<bool>(m+1, false));
        tab[0][0] = true;

        int p = 0;
        while (p < n+m) {
            int y = max(p-n, 0);
            int x = min(p, n);
            while (y <= m && x >= 0) {
                if (tab[x][y]) {
                    if (x < n)
                        tab[x+1][y] = (s3[p] == s1[x]) || tab[x+1][y];
                    if (y < m)
                        tab[x][y+1] = (s3[p] == s2[y]) || tab[x][y+1];
                }

                x--;
                y++;
            }
            p++;
        }

        // for (int i = 0; i <= n; i++) cout<<i<<" ";
        // for (int i = 0; i <= n; i++) {
        //     cout<<endl;
        //     for (int j = 0; j <= m; j++)
        //         cout<<tab[i][j]<<" ";
        // }

        return tab[n][m];
    }
};
