class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l + 1 != r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) break;

            if (sum < target) l++;
            else if (sum > target) r--;
        }

        return {l + 1, r + 1};
    }
};
