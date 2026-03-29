class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tab = {};
        for (int i=0; i < nums.size(); i++) {
            tab[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            const int missing = target - nums[i];
            auto it = find(nums.begin(), nums.end(), missing);

            const int secondIndex = it - nums.begin();

            if (it != nums.end() && secondIndex != i) {

                return {min(i, secondIndex), max(i, secondIndex)};
            }
        }

        return {0, 1};
    }
};