class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool valid[s.size()] = {};

        for (int i = 0; i < s.size(); i++) {
            bool validPos = false;
            for (string word: wordDict) {
                int size = word.size();
                if (i - size + 1 < 0 || (i - size >= 0 && !valid[i - size]))
                    continue;

                bool validWord = true;

                for (int j = 0; j < size; j++) {
                    if (i - j < 0 || word[size - 1 - j] != s[i - j]) {
                        validWord = false;
                        break;
                    }
                }

                if (validWord) {
                    validPos = true;
                    break;
                }
            }

            valid[i] = validPos;
        }

        return valid[s.size()-1];
    }
};
