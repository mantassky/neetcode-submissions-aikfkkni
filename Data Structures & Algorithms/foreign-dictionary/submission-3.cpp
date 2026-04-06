class Solution {
public:

    string foreignDictionary(vector<string>& words) {
        unordered_map<char, int> inDegree;
        unordered_map<char, unordered_set<char>> graph;
        for (string word: words)
            for (char l: word) {
                graph[l] = {};
                inDegree[l] = 0;
            }

        int n = graph.size();
        // create graph
        for (int i = 1; i < words.size(); i++) {
            string prev = words[i-1];
            string curr = words[i];
            for (int j = 0; j < prev.size(); j++) {
                if (j >= curr.size()) return "";
                if (curr[j] != prev[j]) {
                    if (!graph[prev[j]].contains(curr[j])) {
                        inDegree[curr[j]]++;
                        graph[prev[j]].insert(curr[j]);
                    }
                    break;
                }
            }
        }

        for (auto& x: graph) {
            break;
            cout<< x.first<<": ";
            for (char c: x.second) cout<< c<<" ";
            cout<<". inD: "<<inDegree[x.first];
            cout<<endl;
        }

        // topological sort
        queue<char> q;
        for (pair<char, int> x: inDegree)
            if (x.second == 0)
                q.push(x.first);

        string res(n, '.');
        int pos = 0;
        while (!q.empty()) {
            int size = q.size();
            //cout<<"q size: "<<q.size()<<endl;

            for (int i = 0; i < size; i++) {
                char top = q.front();
                q.pop();
                //cout<<"top: "<<top;

                res[pos] = top;
                pos++;
                
                for (char out: graph[top]) {
                    inDegree[out]--;
                    if (inDegree[out] == 0)
                        q.push(out);
                }
            }cout<<endl;
        }

        cout<<res<<endl;
        if (res[n-1] == '.') return "";

        return res;
    }
};
