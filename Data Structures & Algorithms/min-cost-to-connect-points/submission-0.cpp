class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // point - [{dist1, point1}, {dist2, point2}]
        vector<priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        >> closest(n);

        for (int i = 1; i < n; i++)
            closest[i].push({dist(points[i], points[0]), 0});
        
        unordered_set<int> notConnected(n);
        for (int i = 1; i < n; i++) notConnected.insert(i);

        int res = 0;
        while (!notConnected.empty()) {
            int bestIdx = -1;
            int bestDist = INT_MAX;
            for (int nc: notConnected) {
                auto [dist, idx] = closest[nc].top();
                if (dist < bestDist) {
                    bestDist = dist;
                    bestIdx = nc;
                }
            }

            for (int i = 0; i < n; i++)
                if (i != bestIdx)
                    closest[i].push({dist(points[i], points[bestIdx]), bestIdx});

            res += bestDist;
            notConnected.erase(bestIdx);            
        }

        return res;
    }

    int dist(vector<int>& a, vector<int>& b) {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
};
