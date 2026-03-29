class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string x : tokens) {
            if (iswalnum(x[x.length() - 1]))
                stk.push(stoi(x));
            else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                stk.push(calculate(x[0], a, b));
            }
        }

        return stk.top();
    }

    int calculate(char operand, int a, int b) {
        if (operand == '+') return a + b;
        if (operand == '-') return a - b;
        if (operand == '*') return a * b;
        if (operand == '/') return a / b;
    }
};
