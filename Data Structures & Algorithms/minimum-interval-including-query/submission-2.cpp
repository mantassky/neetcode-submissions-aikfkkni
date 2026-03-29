class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> res(queries.size());
        
        multimap<int, int> qm;
        for (int i = 0; i < queries.size(); i++)
            qm.insert({queries[i], i});

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;
        int i = 0;
        for (pair<int, int> qi: qm) {
            cout<<qi.first<<endl;
            while (i < intervals.size() && intervals[i][0] <= qi.first) {
                minHeap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }

            while (!minHeap.empty() && minHeap.top().second < qi.first)
                minHeap.pop();

            if (minHeap.empty())
                res[qi.second] = -1;
            else
                res[qi.second] = minHeap.top().first;
        }

        return res;
    }
};
