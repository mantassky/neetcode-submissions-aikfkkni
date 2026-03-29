class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        int res = 0;

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];
            if (temp[1] <= interval[0]) {
                temp = interval;
                continue;
            }

            res++;
            if (interval[1] < temp[1]) temp = interval;
        }

        return res;
    }

    int overlap(vector<int> a, vector<int> b) {
        return !(a[1] <= b[0] || b[1] <= a[0]);
    }
};
