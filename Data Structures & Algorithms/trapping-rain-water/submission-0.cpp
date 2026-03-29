class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lAreas(n);
        vector<int> rAreas(n);

        // left to right first
        int level = 0;
        for (int i = 0; i < n; i++) {
            if (level <= height[i])
                lAreas[i] = 0;
            else
                lAreas[i] = lAreas[i-1] + level - height[i];
            
            level = max(level, height[i]);
        }

        // maximise
        for (int i = n-2; i >= 0; i--)
            if (lAreas[i] != 0)
                lAreas[i] = max(lAreas[i+1], lAreas[i]);

        // right to left first
        level = 0;
        for (int i = n-1; i >=0; i--) {
            if (level <= height[i])
                rAreas[i] = 0;
            else
                rAreas[i] = rAreas[i+1] + level - height[i];
            
            level = max(level, height[i]);
        }
        // maximise
        for (int i = 1; i < n; i++)
            if (rAreas[i] != 0)
                rAreas[i] = max(rAreas[i-1], rAreas[i]);

        // final step
        int totalArea = 0;
        for (int i = 0; i < n; i++) {
            int currArea = min(lAreas[i], rAreas[i]);
            if (currArea != 0) {
                totalArea += currArea;
                while (i + 1 < n && min(lAreas[i], rAreas[i]) == currArea)
                    i++;
            }
        }
        
        return totalArea;
    }
};
