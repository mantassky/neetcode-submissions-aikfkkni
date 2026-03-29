class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int currMin = 1, currMax = 1;

        for (int num: nums) {
            int tmp = currMax * num;
            currMax = max({tmp, currMin * num, num});
            currMin = min({tmp, currMin * num, num});
            res = max(res, currMax);
        }

        return res;
    }
};
