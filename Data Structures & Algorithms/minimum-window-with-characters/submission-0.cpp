class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tCount;
        unordered_map<char, int> windowCount;
        for (char c: t) tCount[c]++;

        int l = 0;
        int fills = 0;
        int minLength = s.size();
        string res = "";
        for (int r = 0; r < s.size(); r++) {
            char inC = s[r];
            if (tCount.contains(inC)) {
                if (windowCount[inC] + 1 == tCount[inC])
                    fills++;
                windowCount[inC]++;
            }

            while (fills == tCount.size()) {
                char outC = s[l];
                if (r - l + 1 <= minLength) {
                    minLength = r - l + 1;
                    res = s.substr(l, minLength);
                }

                if (tCount.contains(outC)) {
                    if (windowCount[outC] == tCount[outC])
                        fills--;
                    windowCount[outC]--;
                }
                l++;
            }
        }
        
        return res;
    }
};
