class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 1; 
        for (int i = 0; i < 26; i++) {
            int l = -1;
            int kLeft = k;
            char c = indexToChar(i);
            for (int r = 0; r < s.size(); r++) {
                if (s[r] != c) {
                    if (kLeft > 0) kLeft--;
                    else {
                        l++;
                        while (s[l] == c) l++;
                    }
                }
                res = max(res, r - l);
            }
        }

        return res;
    }

    char indexToChar(int i) {
        return 'A' + i;
    }
};
