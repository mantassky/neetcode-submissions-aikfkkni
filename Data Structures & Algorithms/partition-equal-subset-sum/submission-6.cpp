class Solution {
public:
    vector<vector<int>> dp;

    bool canPartition(vector<int>& nums) {
        int t = accumulate(nums.begin(), nums.end(), 0);
        if (t % 2 == 1) return false;
        t /= 2;

        vector<bool> dp(t+1, false);
        dp[0] = true;

        for (int num: nums)
            for (int i = t - num; i >= 0; i--) 
                if (dp[i]) dp[i + num] = true;

        return dp[t];
    }
};
