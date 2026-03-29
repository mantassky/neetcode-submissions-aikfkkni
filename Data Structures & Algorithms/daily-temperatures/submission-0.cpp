class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> stk;
        vector<int> res(n);
        res[n-1] = 0;
        stk.push({temperatures[n-1], 0});

        for (int i = n-2; i >= 0; i--) {
            int days = 0;
            int size = stk.size();
            for (int j = 0; j < size; j++) {
                pair<int, int> top = stk.top();
                if (temperatures[i] < top.first) {
                    res[i] = 1 + days;
                    stk.push({temperatures[i], res[i]});
                    break;
                } else {
                    stk.pop();
                    days += top.second;
                }
            }
            if (stk.empty()) {
                stk.push({temperatures[i], 0});
                res[i] = 0;
            }
        }

        return res;
    }
};
