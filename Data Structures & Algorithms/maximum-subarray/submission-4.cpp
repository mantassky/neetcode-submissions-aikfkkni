class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = res;

        bool prevNeg = nums[0] < 0;
        for (int i = 1; i < nums.size(); i++) {
            if (prevNeg && nums[i] >= 0 && sum < 0)
                sum = nums[i];
            else
                sum+=nums[i];
            
            res = max(sum, res);
            if (nums[i] < 0) {
                prevNeg = true;
                res = max(nums[i], res);
            }
        }

        return res;
    }
};
