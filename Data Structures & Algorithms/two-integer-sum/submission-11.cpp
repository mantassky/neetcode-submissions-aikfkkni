class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tab;

        for (int i = 0; i < nums.size(); i++) {
            const int diff = target - nums[i];
            
            auto it = tab.find(diff);

            if (it != tab.end()) {
                const int secondI = (*it).second;
                return {min(i, secondI), max(i, secondI)};
            }
            tab.insert({nums[i], i});
        }

        return {0, 1};
    }
};