class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int curr = 2, prev = 1;
        
        for (int i = 2; i < n; i++) {
            int next = curr + prev;
            prev = curr;
            curr = next;
        }

        return curr;
    }
};
