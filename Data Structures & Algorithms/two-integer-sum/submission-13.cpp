class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tab;

        for (int i = 0; i < nums.size(); i++) {
            const int diff = target - nums[i];

            if (tab.contains(diff))
                return {min(i, tab[diff]), max(i, tab[diff])};
            
            tab[nums[i]] = i;
        }
    }
};