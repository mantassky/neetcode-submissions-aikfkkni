class Solution {
public:
    int rob(vector<int>& nums) {
        int r1 = 0, r2 = 0;

        for (int num: nums) {
            int temp = max(r2, num + r1);
            r1 = r2;
            r2 = temp;
            cout<<r2<<endl;
        }

        return r2;
    }
};
