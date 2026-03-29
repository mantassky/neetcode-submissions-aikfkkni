class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> nodes(n);
        vector<bool> visited(n);

        for (vector<int> e: edges) {
            nodes[e[0]].insert(e[1]);
            nodes[e[1]].insert(e[0]);
        }

        if (!dfs(nodes, visited, 0)) return false;

        for (bool v: visited)
            if (!v)
                return false;

        return true;
    }

    bool dfs(vector<unordered_set<int>>& nodes, vector<bool>& visited, int node) {
        if (visited[node]) return false;
        
        visited[node] = true;

        unordered_set<int> neighbors = nodes[node];
        for (int n: neighbors) {
            nodes[n].erase(node);
            if (!dfs(nodes, visited, n))
                return false;
        }
        
        return true;
    }
};
