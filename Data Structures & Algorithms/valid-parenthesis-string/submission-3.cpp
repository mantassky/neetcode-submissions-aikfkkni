class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> wild;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') left.push(i);
            else if (s[i] == '*') wild.push(i);
            else { // s[i] == ')'
                if (!left.empty()) {
                    s[left.top()] = '.';
                    left.pop();
                } else if (!wild.empty()) {
                    s[wild.top()] = '.';
                    wild.pop();
                } else return false;
            }
        }

        int wilds = 0;
        for (int i = s.size()-1; i>=0; i--) {
            if (s[i] == '*') wilds++;
            else if (s[i] == '(') wilds--;

            if (wilds < 0) return false;
        }

        return true;
    }
};
