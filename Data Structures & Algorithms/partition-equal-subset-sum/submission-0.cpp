class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<bool> used(nums.size(), false);

        int t = accumulate(nums.begin(), nums.end(), 0);
        if (t % 2 == 1) return false;
        t /= 2;

        return dfs(nums, used, t, 0);
    }

    bool dfs(vector<int>& nums, vector<bool>& used, int t, int i) {
        if (i >= nums.size()) return false;
        if (t < 0) return false;
        if (t == 0) return true;

        used[i] = true;
        bool res = dfs(nums, used, t - nums[i], i+1);
        used[i] = false;
        
        return res || dfs(nums, used, t, i+1);
    }
};
