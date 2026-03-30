class Solution {
public:
    vector<int> delays;
    vector<vector<pair<int, int>>> adj;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k--;
        delays.resize(n, INT_MAX);
        adj.resize(n);

        for (vector<int> edge: times)
            adj[edge[0]-1].push_back({edge[1]-1, edge[2]});

        dfs(k, 0);

        int res = INT_MIN;
        for (int d: delays) {
            if (d == INT_MAX) return -1;
            res = max(res, d);
        }

        return res;
    }

    void dfs(int k, int time) {
        if (delays[k] <= time) return;
        delays[k] = time;

        for (pair<int, int> nb: adj[k])
            dfs(nb.first, time + nb.second);
    }
};
