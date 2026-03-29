class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;

        int step = 0;
        int explored = 0;
        while (step < nums.size() - 1) {
            cout<<step<<" ";
            int limit = min(step + nums[step], (int)nums.size() - 1);
            int bestStep = step;
            for (int i = explored + 1; i <= limit; i++) {
                if (
                    min((int)nums.size() - 1, i+nums[i]) >=
                    min((int)nums.size() - 1, bestStep + nums[bestStep])
                )
                    bestStep = i;
            }
            
            step = bestStep;
            explored = limit;
            res++;
        }

        return res;
    }
};
