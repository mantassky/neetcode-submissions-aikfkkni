class Solution {
public:
    vector<string> res;

    vector<string> phone = {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        string temp = "";
        letterCombinations(digits, 0, temp);
        return res;
    }

    void letterCombinations(string& digits, int index, string& curr) {
        if (index == digits.size()) {
            res.push_back(curr);
            return;
        }

        string letters = phone[digits[index] - '2'];
        for (char c: letters) {
            curr = curr + c;
            letterCombinations(digits, index+1, curr);
            curr.pop_back();
        }
    }
};
