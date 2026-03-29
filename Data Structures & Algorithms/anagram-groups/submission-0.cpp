class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> tab = {};
        for (int i = 0; i < strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());

            auto it = tab.find(sorted);
            if (it != tab.end())
                it->second.push_back(i);
            else
                tab[sorted] = {i};
        }

        vector<vector<string>> result = {};
        for (auto x : tab) {
            vector<string> sub = {};
            for (int i : x.second)
                sub.push_back(strs[i]);
            result.push_back(sub);
        }
        
        return result;
    }
};
