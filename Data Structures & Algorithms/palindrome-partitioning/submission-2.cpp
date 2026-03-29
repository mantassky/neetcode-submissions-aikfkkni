class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        vector<int> divisions = {};
        partition(s, divisions, 1);
        return res;
    }

    void partition(string& s, vector<int>& divisions, int index) {
        if (s.size() == index) {
            bool valid = true;
            int prevD = 0;
            divisions.push_back(s.size());
            vector<string> p;

            for (int d: divisions) {
                p.push_back(s.substr(prevD, d - prevD));
                valid = isPalindrome(p.back());
                if (!valid) break;
                prevD = d;
            }
            divisions.pop_back();
            if (valid)
                res.push_back(p);
            return;
        }

        partition(s, divisions, index+1);
        divisions.push_back(index);
        partition(s, divisions, index+1);
        divisions.pop_back();
    }

    bool isPalindrome(string a) {
        for (int i = 0; i < a.size() / 2; i++)
            if (a[i] != a[a.size()-1-i]) return false;

        return true;
    }
};
