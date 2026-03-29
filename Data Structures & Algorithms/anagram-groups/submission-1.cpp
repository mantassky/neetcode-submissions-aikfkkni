class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tab = {};
        for (int i = 0; i < strs.size(); i++) {
            string encoded = encode(strs[i]);
            tab[encoded].push_back(strs[i]);
        }

        vector<vector<string>> result = {};
        for (auto x : tab) 
            result.push_back(x.second);
        
        return result;
    }

    string encode(string str) {
        string encoding = "";
        int count[26] = {0};

        for (char x : str) {
            int index = x - 'a';
            count[index]++;
        }

        for (int i=0; i<26; i++)
            encoding += (to_string(count[i]) + ".");
        
        return encoding;
    }
};
