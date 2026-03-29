class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        vector<int> merged = intervals[0];
        for (vector<int> interval: intervals) {
            if (overlaps(merged, interval)) {
                merged[0] = min(merged[0], interval[0]);
                merged[1] = max(merged[1], interval[1]);
            } else {
                res.push_back(merged);
                merged = interval;
            }
        }

        res.push_back(merged);

        return res;
    }

    bool overlaps(vector<int> a, vector<int> b) {
        return !(a[1] < b[0] || b[1] < a[0]);
    }
};
