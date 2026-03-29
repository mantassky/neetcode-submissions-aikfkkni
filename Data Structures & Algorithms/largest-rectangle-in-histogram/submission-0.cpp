class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk;
        int maxArea = 0;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            if (stk.empty()) {
                stk.push({0, heights[i]});
                cout<<i<<": (top) "<<stk.top().first<<" "<<stk.top().second<<endl;
                continue;
            }

            pair<int, int> top = stk.top();
            if (top.second < heights[i])
                stk.push({i, heights[i]});
            else if (top.second > heights[i]) {
                int leftWall = 0;

                while (!stk.empty() && stk.top().second > heights[i]) {
                    leftWall = stk.top().first;
                    int height = stk.top().second;
                    int width = i - leftWall;
                    maxArea = max(maxArea, width * height);
                    stk.pop();
                }
                stk.push({leftWall, heights[i]});
            }
            cout<<i<<": (top) "<<stk.top().first<<" "<<stk.top().second<<endl;
        }

        return maxArea;
    }
};
