class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> window;
        vector<int> res;

        int l = 0; // first element of the window
        for (int r = 0; r < nums.size(); r++) {
            l = r - k + 1;
            window[nums[r]]++;
            

            if (l >= 0) {
                auto lastIter = window.rbegin();
                res.push_back(lastIter->first);

                if (window[nums[l]] == 1) window.erase(nums[l]);
                else window[nums[l]]--;
            }
        }

        return res;
    }
};
