class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (nums[0] < nums[n-1]) return nums[0];

        int l = 1;
        int r = n-1;
        int res = nums[r];

        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] > nums[0]) l = mid + 1;
            else {
                res = nums[mid];
                r = mid - 1;
            }
        }

        return res;
    }
};
