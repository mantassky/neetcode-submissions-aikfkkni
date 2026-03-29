class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        string line = string(n*2, ' ');
        generateParenthesis(n, 0, 0, line);
        return res;
    }

    void generateParenthesis(int n, int oUsed, int cUsed, string& line) {
        if (oUsed == n && cUsed == n) {
            res.push_back(line);
            return;
        }

        if (oUsed > cUsed) {
            line[oUsed + cUsed] = ')';
            generateParenthesis(n, oUsed, cUsed+1, line);
        }
        if (n != oUsed) {
            line[oUsed + cUsed] = '(';
            generateParenthesis(n, oUsed+1, cUsed, line);
        }
    }
};
