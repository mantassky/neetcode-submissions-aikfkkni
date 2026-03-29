class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> tab;

        for (int x: nums) {
            tab.push(x);
            if (tab.size() > k) tab.pop();
        }

        return tab.top();
    }
};
