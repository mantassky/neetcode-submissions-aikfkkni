class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> tab = {};
        for (int i = 0; i < s.length(); i++) {
            if (tab.contains(s[i])) {
                tab[s[i]] = tab[s[i]] + 1;
            } else tab[s[i]] = 1;
        }

        for (int i = 0; i < t.length(); i++) {
            if (!tab.contains(t[i])) return false;
            tab[t[i]] = tab[t[i]] - 1;
        }

        for (const auto& [key, value] : tab) {
            cout<< key << " , " << value << endl;
        }

        for (const auto& [key, value] : tab) {
            if (value != 0) return false;
        }

        return true;
    }
};
