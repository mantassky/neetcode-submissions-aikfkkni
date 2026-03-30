class Solution {
public:

    vector<vector<pair<int, int>>> adj;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        adj.resize(n+1);
        vector<bool> visited(n+1, false);

        for (vector<int> edge: times)
            adj[edge[0]].push_back({edge[2], edge[1]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        for (pair<int, int> edge: adj[k])
            q.push(edge);

        int res = -1;
        visited[k] = true;
        while (!q.empty()) {
            pair<int, int> front = q.top();
            q.pop();

            int toNode = front.second;
            int time = front.first;

            if (visited[toNode]) continue;
            res = max(res, time);
            visited[toNode] = true;

            for (pair<int, int> edge: adj[toNode])
                q.push({edge.first + time, edge.second});
        }

        for (int i = 1; i <= n; i++)
            if (!visited[i]) return -1;

        return res;
    }
};
