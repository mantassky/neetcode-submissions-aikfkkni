class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int sum = 0;
        for (int i = 0; i < n; i++) sum += (gas[i]-cost[i]);
        if (sum < 0) return -1;

        int start = 0;
        while (start < n && gas[start] < cost[start]) start++;
        if (start == n) return -1;

        int currStart = start;
        int i = start;
        int currRun = 0;
        int steps = 0;
        cout<<"start: "<<start<<endl;
        while (steps < n) {
            int idx = i % n;
            int gain = gas[idx] - cost[idx];
            currRun += gain;
            
            if (currRun < 0) {
                currStart = (i+1)%n;
                currRun = 0;
                steps = 0;
            }

            i++;
            steps++;
        }

        return currStart;
    }
};
