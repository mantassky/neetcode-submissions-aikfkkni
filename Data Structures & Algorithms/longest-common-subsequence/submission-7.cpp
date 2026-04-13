class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> ln(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool match = (text1[j] == text2[i]);
                int top = ln[j];
                int left = j != 0 ? ln[j-1] : 0;
                ln[j] = ((top == left) && match) ? top + 1 : max(top, left);
            }
        }

        return ln[n-1];
    }
};
