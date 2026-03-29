class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int start = 0;
        int prod = 1;
        int negs = 0;

        for (int i = 0; i <= nums.size(); i++) {
            if (i != nums.size() && nums[i] == 0) res = max(0, res);

            if (i == nums.size() || nums[i] == 0) {
                res = max(res, getMaxFromRange(nums, start, i, prod, negs));
                cout<<res<<endl;
                prod = 1;
                negs = 0;
                start = i+1;
            } else {
                prod *= nums[i];
                if (nums[i] < 0) negs++;
            }
        }
        

        return res;
    }

    int getMaxFromRange(vector<int>& nums, int start, int end, int prod, int negs) {
        if (start == end) return 0;
        if (negs % 2 == 0) return prod;
        if (end - start == 1) return nums[start];

        int i = start;
        int res1 = prod;
        while (nums[i] > 0) {
            res1 /= nums[i];
            i++;
        }
        res1 /= nums[i];
        
        i = end-1;
        int res2 = prod;
        while (nums[i] > 0) {
            res2 /= nums[i];
            i--;
        }
        res2 /= nums[i];

        return max(res1, res2);
    }
};
