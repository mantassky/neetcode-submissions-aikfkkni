class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        combinationSum(nums, target, {});
        return res;
    }

    void combinationSum(vector<int>& nums, int target, vector<int> subset) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        if (target < 0) return;

        for (int num: nums) {
            if (!subset.empty() && subset.back() > num) continue;
            subset.push_back(num);
            combinationSum(nums, target - num, subset);
            subset.pop_back();
        }
    }
};
