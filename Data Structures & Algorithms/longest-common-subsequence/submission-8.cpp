class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> ln(n+1, 0);

        for (int i = m-1; i >= 0; i--) {
            int prev = 0;
            for (int j = n-1; j >= 0; j--) {
                int temp = ln[j];
                if (text1[j] == text2[i])
                    ln[j] = prev + 1;
                else
                    ln[j] = max(ln[j], ln[j+1]);
                prev = temp;
            }
        }

        return ln[0];
    }
};
