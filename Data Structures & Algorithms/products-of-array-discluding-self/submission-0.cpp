class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroes = 0;
        int zeroIndex = -1;

        long product = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroIndex = i;
                zeroes++;
            }
            else
                product *= nums[i];
        }

        vector<int> result;
        if (zeroes > 0) {
            for (int i = 0; i < nums.size(); i++)
                result.push_back(0);

            if (zeroes == 1)
                result[zeroIndex] = product;

            return result;
        }
        
        for (int i = 0; i < nums.size(); i++)
            result.push_back(product / nums[i]);

        return result;
    }
};
