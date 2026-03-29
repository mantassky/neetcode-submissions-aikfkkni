class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> valid(3);

        for (vector<int> triplet: triplets) {
            bool invalid = false;
            for (int i = 0; i < 3; i++)
                if (triplet[i] > target[i]) invalid = true;
            if (invalid) continue;

            for (int i = 0; i < 3; i++)
                if (triplet[i] == target[i]) valid[i] = true;
        }

        for (bool x: valid)
            if (!x) return false;

        return true;
    }
};
