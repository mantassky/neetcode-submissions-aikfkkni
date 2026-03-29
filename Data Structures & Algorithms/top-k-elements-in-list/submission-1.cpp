class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int count[2001] = {0};
        for (int x : nums)
            count[x + 1000]++;
        
        priority_queue<pair<int, int>> rank;
        for (int i = 0; i < 2001; i++)
            if (count[i] != 0)
                rank.push({count[i], i - 1000});
        
        vector<int> result = {};
        for (int i = 0; i < k; i++) {
            result.push_back(rank.top().second);
            rank.pop();
        }
        
        return result;
    }
};
