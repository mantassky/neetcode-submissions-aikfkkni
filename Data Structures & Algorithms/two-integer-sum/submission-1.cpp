class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> tab = {};
        for (int x : nums) tab.insert(x);

        for (int i = 0; i < nums.size(); i++) {
            if (tab.contains(target - nums[i])) {
                for (int j = 0; j < nums.size(); j++) {
                    if (target - nums[i] == nums[j] && i != j)
                        return {min(i, j), max(i, j)};
                }
            }
        }

        return {0, 1};
    }
};