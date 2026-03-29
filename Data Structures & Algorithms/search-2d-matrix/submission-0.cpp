class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0, end = m * n;

        while (start < end) {
            int mid = start + (end - start) / 2;

            int value = matrix[mid/n][mid%n];
            if (value == target) return true;
            if (value < target && start != mid) start = mid;
            else end = mid;
        }

        int value = matrix[start/n][start%n];
        if (value == target) return true;

        return false;
    }
};
