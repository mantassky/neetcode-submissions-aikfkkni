class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> ls;

        int res=0;
        for (int x : nums) {
            if (!ls[x]) {
                ls[x] = ls[x-1] + ls[x+1] + 1;
                ls[x - ls[x-1]] = ls[x];
                ls[x + ls[x+1]] = ls[x];
                res = max(res, ls[x]);
            }
        }
        for (auto x : ls)
            cout << x.first << ": " << x.second << endl;

        return res;
    }
};
