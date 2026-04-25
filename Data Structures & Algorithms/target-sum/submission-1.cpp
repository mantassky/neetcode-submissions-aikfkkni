class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;

        dp[0] = 1;
        for (int num: nums) {
            unordered_map<int, int> newDp;
            for (auto& [key, value]: dp) {
                newDp[key-num] += value;
                newDp[key+num] += value;
            }
            dp = newDp;
        }

        return dp[target];
    }
};
