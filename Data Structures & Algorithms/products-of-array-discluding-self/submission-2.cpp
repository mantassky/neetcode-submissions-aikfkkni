class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix_b = 1;
        int suffix_b = 1;
        vector<int> result(n);

        for (int i = 0; i < n; i++)
            result[i] = 1;
        
        for (int i = 1; i < n; i++) {
            prefix_b *= nums[i-1];
            result[i] *= prefix_b;

            suffix_b *= nums[n-i];
            result[n-1-i] *= suffix_b;
        }
        
        return result;
    }
};
