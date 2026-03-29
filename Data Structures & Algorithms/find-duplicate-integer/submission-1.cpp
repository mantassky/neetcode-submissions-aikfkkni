class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int v = abs(nums[i]);
            if (nums[v - 1] < 0) return v;
            nums[v - 1] = -nums[v - 1];
        }

        return 0;
    }
};
