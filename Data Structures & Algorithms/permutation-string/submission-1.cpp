class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> windowCount;
        unordered_map<char, int> s1Count;
        int count = 0;
        for (char c : s1) s1Count[c]++;

        for (int r = 0; r < s2.size(); r++) {
            int l = r - s1.size();
            if (l >= 0 && s1Count.contains(s2[l])) {
                char outC = s2[l];
                if (s1Count[outC] == windowCount[outC])
                    count--;
                
                windowCount[outC]--;
                if (s1Count[outC] == windowCount[outC])
                    count++;
            }

            char inC = s2[r];
            if (s1Count.contains(inC)) {
                if (s1Count[inC] == windowCount[inC])
                    count--;
                
                windowCount[inC]++;
                if (s1Count[inC] == windowCount[inC])
                    count++;
            }

            if (count == s1Count.size()) return true;
        }

        return false;
    }
};
