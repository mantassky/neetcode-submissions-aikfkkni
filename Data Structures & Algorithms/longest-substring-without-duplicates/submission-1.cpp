class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int l = 0;
        unordered_set<char> subs = {};
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (subs.contains(c)) {
                while (s[l] != c) {
                    subs.erase(s[l]);
                    l++;
                }
                subs.erase(s[l]);
                l++;
            }
            
            subs.insert(c);
            
            longest = max(longest, i - l + 1);
        }

        return longest;
    }
};
