class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t = accumulate(nums.begin(), nums.end(), 0);
        if (t % 2 == 1) return false;
        t /= 2;

        return dfs(nums, t, 0);
    }

    bool dfs(vector<int>& nums, int t, int i) {
        if (i >= nums.size()) return false;
        if (t < 0) return false;
        if (t == 0) return true;

        bool res = dfs(nums, t - nums[i], i+1);
        
        return res || dfs(nums, t, i+1);
    }
};
