class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int x : nums)
            count[x]++;
        
        vector<vector<int>> freq(nums.size() + 1);
        for (const auto& x : count)
            freq[x.second].push_back(x.first);
        
        vector<int> result;
        for (int i = freq.size() - 1; i >= 0; i--) {
            for (int j = 0; j < freq[i].size(); j++) {
                result.push_back(freq[i][j]);
                if (result.size() == k)
                    return result;
            }
        }
        
        return result;
    }
};
