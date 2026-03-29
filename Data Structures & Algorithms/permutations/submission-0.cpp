class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> perm;
        permute(nums, perm, used);
        return res;
    }

    void permute(vector<int>& nums, vector<int>& perm, vector<bool>& used) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < used.size(); i++) {
            if (used[i]) continue;

            perm.push_back(nums[i]);
            used[i] = true;
            permute(nums, perm, used);
            perm.pop_back();
            used[i] = false;
        }
    }
};
