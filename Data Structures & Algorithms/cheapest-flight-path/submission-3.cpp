class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        vector<int> minCost(n, INT_MAX);

        for (vector<int> f: flights)
            adj[f[0]].push_back({f[1], f[2]}); // to, cost
        
        queue<pair<int, int>> q; // airport, cost
        q.push({src, 0});
        int stops = 0;
        while (!q.empty() && stops <= k+1) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> curr = q.front();
                q.pop();

                if (curr.second >= minCost[curr.first]) continue;
                minCost[curr.first] = curr.second;

                for (pair<int, int> f: adj[curr.first])
                    q.push({f.first, curr.second + f.second});
            }
            stops++;
        }

        if (minCost[dst] == INT_MAX) return -1;
        return minCost[dst];
    }
};
