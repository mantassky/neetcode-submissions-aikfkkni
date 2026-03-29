class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        subsetsWithDup(nums, subset, 0);
        return res;
    }

    void subsetsWithDup(vector<int>& nums, vector<int>& subset, int index) {
        if (index == nums.size()) {
            res.push_back(subset);
            return;
        }

        int val = nums[index];
        int nextIndex = index;
        while (nextIndex < nums.size() && nums[nextIndex] == val) nextIndex++;

        subsetsWithDup(nums, subset, nextIndex);
        for (int i = index; i < nextIndex; i++) {
            subset.push_back(val);
            subsetsWithDup(nums, subset, nextIndex);
        }

        for (int i = index; i < nextIndex; i++) subset.pop_back();
    }
};
