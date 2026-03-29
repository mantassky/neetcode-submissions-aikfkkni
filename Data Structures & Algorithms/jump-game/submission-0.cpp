class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpLeft = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size()-1) return true;

            jumpLeft = max(jumpLeft, nums[i]);
            if (jumpLeft == 0) return false;
            
            jumpLeft--;
        }

        return false;
    }
};
