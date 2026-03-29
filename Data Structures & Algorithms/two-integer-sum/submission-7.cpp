class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> numsSorted = nums;
        sort(numsSorted.begin(), numsSorted.end());

        int i = 0;
        int j = numsSorted.size()-1;
        int a,b;

        while (i != j) {
            const int sum = numsSorted[i] + numsSorted[j];
            if (target < sum) j--;
            else if (sum < target) i++;
            else {
                a = numsSorted[i];
                b = numsSorted[j];
                break;
            }
        }

        int firstI=0;
        int secondI=0;
        for (int i = 0; i< nums.size(); i++)
            if (a == nums[i]) {firstI = i; break;}

        for (int i = 0; i< nums.size(); i++)
            if (b == nums[i] && firstI != i) {secondI = i; break;}
        

        return {min(firstI, secondI), max(firstI, secondI)};
    }
};