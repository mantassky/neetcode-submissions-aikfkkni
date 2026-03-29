/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool compare(Interval& a, Interval& b) {
        return a.start < b.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> counts;
        for (Interval i: intervals) {
            counts[i.start]++;
            counts[i.end]--;
        }

        int res = 0;
        int count = 0;
        for (pair<int, int> c: counts) {
            count += c.second;
            res = max(res, count);
        }
        
        return res;
    }
};
