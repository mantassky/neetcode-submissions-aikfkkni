class Solution {
public:
    struct Compare {
        bool operator()(pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();

        unordered_map<char, int> freq;
        for (char task: tasks) freq[task]++;

        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> qu;
        for (auto task: freq) qu.push({task.first, task.second});

        int count = 0;
        while (!qu.empty()) {
            vector<pair<char, int>> temp = {};
            for (int i = 0; i <= n; i++) {
                if (!qu.empty()) {
                    count++;
                    pair<char, int> top = qu.top();
                    if (top.second != 1)
                        temp.push_back({top.first, top.second-1});
                    qu.pop();
                } else if (!temp.empty()) count++;
            }


            for (auto task: temp) {
                cout<<task.first<<": "<<task.second<<endl;
                qu.push(task);
            }cout<<endl;
        }

        return count;
    }
};
