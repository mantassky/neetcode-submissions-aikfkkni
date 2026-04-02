class Solution {
public:
    stack<string> res;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> out;

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (vector<string> t: tickets)
            out[t[0]].push(t[1]);
        
        dfs("JFK");

        vector<string> realRes;
        while (!res.empty()) {
            realRes.push_back(res.top());
            res.pop();
        }
        return realRes;
    }

    void dfs(string curr) {        
        while (!out[curr].empty()) {
            string next = out[curr].top();
            out[curr].pop();
            dfs(next);
        }

        res.push(curr);
    }
};
