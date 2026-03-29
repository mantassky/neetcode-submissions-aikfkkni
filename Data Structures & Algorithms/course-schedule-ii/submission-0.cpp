class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> courses(numCourses);
        vector<int> inDegree(numCourses);

        queue<int> q;

        for (vector<int> p: prerequisites) {
            courses[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int c = q.front();
            q.pop();

            res.push_back(c);
            for (int next: courses[c]) {
                inDegree[next]--;
                if (inDegree[next] == 0)
                    q.push(next);
            }
            courses[c].clear();
        }

        if (res.size() != numCourses) return {};

        return res;
    }
};
