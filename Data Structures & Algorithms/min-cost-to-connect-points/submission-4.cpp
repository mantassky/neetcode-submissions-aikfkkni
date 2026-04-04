class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist2tree(n, INT_MAX);
        vector<bool> connected(n, false);
        connected[0] = true;
        int curr = 0;
        
        int res = 0;
        for (int a = 1; a < n; a++) {
            int next = -1;
            for (int i = 0; i < n; i++) {
                if (connected[i]) continue;

                dist2tree[i] = min(dist(points[curr], points[i]), dist2tree[i]);
                if (next == -1 ||  dist2tree[i] < dist2tree[next])
                    next = i;
            }

            res += dist2tree[next];
            connected[next] = true;
            curr = next;
        }

        return res;
    }

    int dist(vector<int>& a, vector<int>& b) {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
};
