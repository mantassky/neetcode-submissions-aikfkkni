class Solution {
public:
    int rob(vector<int>& nums) {
        int first = nums[0];
        if (nums.size() == 1) return first;
        nums[0] = 0;

        int res = robOG(nums);
        nums[0] = first;
        nums[nums.size()-1] = 0;
        return max(res, robOG(nums));
    }

    int robOG(vector<int>& nums) {
        int r1 = 0, r2 = 0;

        for (int num: nums) {
            int temp = max(r1 + num, r2);
            r1 = r2;
            r2 = temp;
        }

        return r2;
    }
};
