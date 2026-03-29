class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums, 0);
        return res;
    }

    void permute(vector<int>& nums, int index) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            permute(nums, index+1);
            swap(nums[i], nums[index]);
        }
    }
};
