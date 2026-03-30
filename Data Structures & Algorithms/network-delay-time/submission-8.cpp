class Solution {
public:

    vector<vector<pair<int, int>>> adj;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        adj.resize(n+1);
        unordered_set<int> visited;

        for (vector<int> edge: times)
            adj[edge[0]].push_back({edge[2], edge[1]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({0, k});

        int res = -1;
        while (!q.empty()) {
            pair<int, int> front = q.top();
            q.pop();

            int toNode = front.second;
            int time = front.first;

            if (visited.contains(toNode)) continue;
            res = max(res, time);
            visited.insert(toNode);

            for (pair<int, int> edge: adj[toNode])
                q.push({edge.first + time, edge.second});
        }

        if (visited.size() != n) return -1;

        return res;
    }
};
