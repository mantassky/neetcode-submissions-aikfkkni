class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> stk;
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top().first < temperatures[i]) {
                int beatIndex = stk.top().second;
                res[beatIndex] = i - beatIndex;
                stk.pop();
            }
            stk.push({temperatures[i], i});
        }

        return res;
    }
};
