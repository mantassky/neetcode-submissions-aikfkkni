class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> tab;
        for (int x : nums)
            tab.insert(x);

        vector<int> starts;
        for (int x : tab)
            if (!tab.contains(x-1))
                starts.push_back(x);
        
        int maxi = 0;
        for (int x : starts) {
            int temp = 1;
            while (tab.contains(x+temp))
                temp++;
            maxi = max(maxi, temp);
        }

        return maxi;
    }
};
