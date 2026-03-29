class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";

        for (char x : s) {
            if (!iswalnum(x)) continue;
            if (x == ' ') continue;
            a += tolower(x);
        }

        for (int i = 0; i < a.length() / 2; i++) {
            if (a[i] != a[a.length() - 1 - i])
                return false;
        }
        
        return true;
    }
};
