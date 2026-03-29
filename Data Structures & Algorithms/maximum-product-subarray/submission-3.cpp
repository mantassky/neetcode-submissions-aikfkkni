class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int currMin = 1, currMax = 1;

        for (int num: nums) {
            int tmp = currMax * num;
            currMax = maxx(tmp, currMin * num, num);
            currMin = minn(tmp, currMin * num, num);
            res = max(res, currMax);
        }

        return res;
    }

    int minn(int a, int b, int c) {
        return min(a, min(b, c));
    }

    int maxx(int a, int b, int c) {
        return max(a, max(b, c));
    }
};
