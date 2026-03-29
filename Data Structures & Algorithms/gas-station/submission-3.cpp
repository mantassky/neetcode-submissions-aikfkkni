class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int sum = 0;
        for (int i = 0; i < n; i++) sum += (gas[i]-cost[i]);
        if (sum < 0) return -1;

        int currRun = 0;
        int currStart = 0;
        for (int i = 0; i < n; i++) {
            int gain = gas[i] - cost[i];
            currRun += gain;
            
            if (currRun < 0) {
                currRun = 0;
                currStart = i+1;
            }
        }

        return currStart;
    }
};
