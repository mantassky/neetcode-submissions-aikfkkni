class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tab;

        for (int i = 0; i < nums.size(); i++) {
            tab.insert({nums[i], i});
            const int diff = target - nums[i];
            
            auto it = tab.find(diff);

            if (it != tab.end()) {
                const int secondI = (*it).second;
                if (secondI != i)
                    return {min(i, secondI), max(i, secondI)};
            }
        }

        return {0, 1};
    }
};