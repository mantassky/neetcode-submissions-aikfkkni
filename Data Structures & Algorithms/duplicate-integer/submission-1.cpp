class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, bool> tab = {};
        for (int i=0;i < nums.size(); i++) {
            if (tab.contains(nums[i])) return true;
            tab[nums[i]] = true;
            cout << tab.at(nums[i]);
        }
        return false;
    }
};