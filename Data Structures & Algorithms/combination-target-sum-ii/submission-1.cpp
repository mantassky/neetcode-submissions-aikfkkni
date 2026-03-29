class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, {}, target, 0);
        return res;
    }

    void combinationSum2(vector<int>& candidates, vector<int> subset, int target, int index) {
        if (target == 0) res.push_back(subset);

        if (target < 0 || index == candidates.size()) return;

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i-1]) continue;

            int val = candidates[i];
            subset.push_back(val);
            combinationSum2(candidates, subset, target - val, i + 1);
            subset.pop_back();
        }
    }
};
