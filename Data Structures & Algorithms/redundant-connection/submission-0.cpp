class Solution {
public:
    unordered_set<int> visitedG;
    int nodeG;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> nodes(n+1);
        for (vector<int> edge: edges) {
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> v;
        dfs(nodes, v, 1, -1);
        dfs(nodes, v, nodeG, -1);

        vector<int> res(2, -1);
        for (vector<int> edge: edges)
            if (visitedG.contains(edge[0]) && visitedG.contains(edge[1]))
                res = edge;
        
        return res;
    }

    void dfs(vector<vector<int>>& nodes, unordered_set<int>& visited, int node, int parent) {
        if (visited.contains(node)) {
            visitedG = visited;
            nodeG = node;
            return;
        }

        visited.insert(node);
        for (int n: nodes[node])
            if (n != parent)
                dfs(nodes, visited, n, node);

        visited.erase(node);
    }
};
