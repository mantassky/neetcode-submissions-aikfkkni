class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b_i = 0; // bought value
        int n = prices.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int bVal = prices[b_i];
            int prevRes = i > 1 ? res[i-2] : 0;
            int cVal = prices[i]; // current value

            // we're buying
            if (res[b_i] - bVal <= prevRes - cVal) {
                b_i = i;
                res[i] = res[i-1];

            // we're trying to sell
            } else {
                int cProfit = prices[i] - prices[b_i];
                res[i] = max(cProfit + (b_i > 1 ? res[b_i - 2] : 0), res[i-1]);
            }
        }

        return res[n-1];
    }
};
