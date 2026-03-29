class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char x : s) {
            if (isOpening(x))
                stk.push(x);
            else if (stk.empty())
                return false;
            else {
                char top = stk.top();
                if (validClosing(top, x))
                    stk.pop();
                else
                    return false;
            }
        }

        if (stk.empty())
            return true;
        
        return false;
    }

    bool validClosing(char a, char b) {
        return (a == '(' && b == ')') ||
               (a == '{' && b == '}') ||
               (a == '[' && b == ']');
    }

    bool isOpening(char a) {
        return a == '(' || a == '{' || a == '[';
    }
};
