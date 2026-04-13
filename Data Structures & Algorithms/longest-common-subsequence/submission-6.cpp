class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> ln(n, 0);
        vector<bool> nMatch(n, false);
        vector<bool> mMatch(m, false);

        for (int i = 0; i < m; i++) {
            cout<<endl << "i: "<<i<<". ";
            for (int j = 0; j < n; j++) {
                bool match = (text1[j] == text2[i]);
                int top = ln[j];
                int left = j != 0 ? ln[j-1] : 0;
                ln[j] = ((top == left) && match) ? top + 1 : max(top, left);
                nMatch[i] = nMatch[i] || match;
                mMatch[j] = mMatch[j] || match;
                cout<<ln[j]<<" "<<(match?"x ":". ");
            }
        }

        return ln[n-1];
    }
};
