class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};
        
        int mStart = INT_MAX;
        int mEnd = INT_MIN;
        int insertionIndex = -1;

        for (int i = 0; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];

            if (overlaps(interval, newInterval)) {
                mStart = min(min(mStart, interval[0]), newInterval[0]);
                mEnd = max(max(mEnd, interval[1]), newInterval[1]);
                intervals[i][0] = -1;
            }
        }

        // if no overlaps
        if (mStart == INT_MAX) {
            for (int i = 0; i < intervals.size(); i++) {
                if (newInterval[0] < intervals[i][0]) {
                    intervals.insert(intervals.begin()+i, newInterval);
                    return intervals;
                }
            }
            intervals.push_back(newInterval);
        } else {
            bool inserted = false;
            int emptyCount = 0;
            for (int i = 0; i < intervals.size(); i++) {
                if (intervals[i][0] == -1) {
                    if (!inserted) {
                        intervals[i] = {mStart, mEnd};
                        inserted = true;
                    }
                    else emptyCount++;
                }
            }
            cout<<emptyCount<<" :count"<<endl;

            if (emptyCount == 0) return intervals;

            bool found = false;
            for (int i = 0; i < intervals.size(); i++) {
                if (intervals[i][0] == -1) found = true;

                if (found && i + emptyCount < intervals.size())
                    intervals[i] = intervals[i + emptyCount];
            }

            for (int i = 0; i < emptyCount; i++) intervals.pop_back();
        }

        return intervals;
    }

    bool overlaps(vector<int> a, vector<int> b) {
        return !(a[1] < b[0] || b[1] < a[0]);
    }
};
