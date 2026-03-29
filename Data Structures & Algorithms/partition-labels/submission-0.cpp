class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> ends;
        for (int i = 0; i < s.size(); i++) 
            ends[s[i]] = i;
        
        int i = 0;
        vector<int> res;
        while (i < s.size()) {
            int end = ends[s[i]];
            int start = i;
            while (i <= end) {
                end = max(end, ends[s[i]]);
                i++;
            }

            res.push_back(i - start);
        }

        return res;
    }
};
