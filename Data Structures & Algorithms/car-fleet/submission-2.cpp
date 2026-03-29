class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> sorted;
        for (int i = 0; i < n; i++)
            sorted.push_back({position[i], speed[i]});

        sort(sorted.begin(), sorted.end());
        
        int fleets = 0;
        double fleetTime = 0;
        for (int i = n-1; i >= 0; i--) {
            double time = double(target - sorted[i].first) / sorted[i].second;
            
            cout<<time<<" ";
            if (time > fleetTime) {
                fleets++;
                fleetTime = time;
            }
        }

        return fleets;
    }
};
