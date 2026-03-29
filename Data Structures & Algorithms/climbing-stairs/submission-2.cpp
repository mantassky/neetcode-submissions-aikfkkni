class Solution {
public:
    int climbStairs(int n) {
        int curr = 1, prev = 0;
        
        for (int i = 0; i < n; i++) {
            int next = curr + prev;
            prev = curr;
            curr = next;
        }

        return curr;
    }
};
