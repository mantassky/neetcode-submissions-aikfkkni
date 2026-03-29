class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxB = 0;
        for (int x: piles)
            maxB = max(maxB, x);

        int kMin = 1;
        int kMax = maxB;
        double hTarget = 0.5 + h;

        while (kMin + 1 < kMax) {
            int kMid = kMin + (kMax - kMin) / 2;

            int time = 0;
            for (int i = 0; i < piles.size(); i++)
                time += (piles[i] / kMid + (piles[i] % kMid > 0 ? 1 : 0));

            if (time > hTarget) kMin = kMid;
            else kMax = kMid;
            cout<<"min, max: "<<kMin<<", "<<kMax<<endl;
        }

        if (kMin == 1) {
            int time = 0;
            for (int i = 0; i < piles.size(); i++)
                time += piles[i];
            if (time <= h) return kMin;
        }

        return kMax;
    }
};
