class Solution {
public:
    struct Node {
        int val;
        vector<Node*> children;
        Node(int val) : val(val) {};
    };

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() <= 1) return true;

        vector<Node*> courses(numCourses); //course, hasIncoming
        vector<bool> hasIncoming(numCourses, false);
        vector<bool> explored(numCourses, false);

        for (int i = 0; i < numCourses; i++) courses[i] = new Node(i);

        for (vector<int> p: prerequisites) {
            courses[p[1]]->children.push_back(courses[p[0]]);
            hasIncoming[p[0]] = true;
        }

        for (int i = 0; i < numCourses; i++) {
            if (hasIncoming[i]) continue;

            unordered_set<int> visited;
            if (!dfs(visited, explored, courses[i])) return false;
        }

        for (int i = 0; i < numCourses; i++) {
            if (explored[i]) continue;

            Node* n = courses[i];
            if (n->children.size() > 0) return false;
        }

        return true;
    }

    bool dfs(unordered_set<int>& visited, vector<bool>& explored, Node* course) {
        if (course->children.empty()) return true;

        if (visited.contains(course->val)) return false;
        visited.insert(course->val);
        explored[course->val] = true;

        bool res = true;
        for (Node* c: course->children)
            res = res && dfs(visited, explored, c);
        
        visited.erase(course->val);

        return res;
    }
};
