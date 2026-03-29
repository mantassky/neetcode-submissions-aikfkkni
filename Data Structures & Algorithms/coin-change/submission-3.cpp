class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> tab;
        tab[amount] = 0;

        for (int coin: coins) {
            unordered_map<int, int> temp(tab);

            for (pair<int, int> entry: tab) {
                int curr = entry.first - coin;
                int steps = entry.second + 1;

                while (curr >= 0) {
                    if (temp.contains(curr))
                        steps = min(temp[curr], steps);
                    
                    temp[curr] = steps;
                    
                    steps++;
                    curr -= coin;
                }
            }

            tab = temp;
        }

        if (!tab.contains(0)) return -1;
        return tab[0];
    }
};
