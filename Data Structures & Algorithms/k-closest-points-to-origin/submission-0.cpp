class Solution {
public:
    struct Compare {
        bool operator()(vector<int> a, vector<int> b) {
            double aDist = sqrt(pow(a[0], 2) + pow(a[1], 2));
            double bDist = sqrt(pow(b[0], 2) + pow(b[1], 2));

            return aDist < bDist;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> tab;

        for (vector<int> point: points) {
            tab.push(point);
            if (tab.size() > k) tab.pop();
        }

        vector<vector<int>> res;
        while (!tab.empty()) {
            res.push_back(tab.top());
            tab.pop();
        }
        return res;
    }
};
