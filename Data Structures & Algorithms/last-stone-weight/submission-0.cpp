class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> tab;
        for (int x: stones) tab.push(x);

        while (tab.size() > 1) {
            int a = tab.top();
            tab.pop();
            int b = tab.top();
            tab.pop();

            int newStone = max(a, b) - min(a, b);
            if (newStone) tab.push(newStone);
        }

        if (tab.empty()) return 0;

        return tab.top();
    }
};
