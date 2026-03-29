class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> tab(amount+1, INT_MAX);

        tab[0] = 0;

        for (int i = 1; i < amount+1; i++) {
            for (int coin: coins) {
                int prevA = i - coin;
                if (prevA >= 0 && tab[prevA] != INT_MAX)
                    tab[i] = min(tab[i], tab[prevA]+1);
            }
        }

        if (tab[amount] == INT_MAX) return -1;

        for (int i = 0; i < amount+1; i++) cout<< tab[i]<<" ";

        return tab[amount];
    }
};
