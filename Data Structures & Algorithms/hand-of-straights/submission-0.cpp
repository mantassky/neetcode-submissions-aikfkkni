class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> freq;
        for (int card: hand) freq[card]++;

        while (!freq.empty()) {
            auto iter = freq.begin();
            int prev = iter->first;
            for (int i = 0; i < groupSize; i++) {
                if (freq.empty()) return false;

                int value = iter->first;
                if (i != 0 && prev + 1 != value) return false;
                prev = value;

                freq[value]--;

                if (freq[value] == 0)
                    iter = freq.erase(iter);
                else
                    iter++; 
            }
        }

        return true;
    }
};
