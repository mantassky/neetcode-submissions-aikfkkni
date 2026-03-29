class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        subsets(nums, 0, used);
        return res;
    }

    void subsets(vector<int>& nums, int index, vector<bool>& used) {
        if (nums.size() == index) {
            vector<int> subset;
            for (int i = 0; i < used.size(); i++)
                if (used[i]) subset.push_back(nums[i]);
            
            res.push_back(subset);
            return;
        }
        used[index] = false;
        subsets(nums, index+1, used);

        used[index] = true;
        subsets(nums, index+1, used);
    }
};
