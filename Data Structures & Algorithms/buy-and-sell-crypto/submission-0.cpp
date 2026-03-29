class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int rHigh = 0;

        for (int i = prices.size() - 1; i >= 0; i--) {
            profit = max(rHigh - prices[i], profit);
            rHigh = max(rHigh, prices[i]);
        }

        return profit;
    }
};
