class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n);

        vector<vector<int>> nodes(n);
        for (vector<int> e: edges) {
            nodes[e[0]].push_back(e[1]);
            nodes[e[1]].push_back(e[0]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            clear(visited, nodes, i);
            res++;
        }

        return res;
    }

    void clear(vector<bool>& visited, vector<vector<int>> nodes, int node) {
        // if (visited[node]) return;
        visited[node] = true;
        
        for (int n: nodes[node])
            if (!visited[n])
                clear(visited, nodes, n);
    }
};
