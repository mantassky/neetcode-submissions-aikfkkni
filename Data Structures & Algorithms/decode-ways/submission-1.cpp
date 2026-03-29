class Solution {
public:
    int numDecodings(string s) {
        int n1 = 1, n2 = 1;

        for (int i = 0; i < s.size(); i++) {
            int temp = 0;
            
            if (s[i] != '0')
                temp = n2;
            if (i > 0 && isValidTwoDigit(s[i-1], s[i]))
                temp += n1;
            
            n1 = n2;
            n2 = temp;
        }

        return n2;
    }

    bool isValidTwoDigit(char a, char b) {
        return (
            a == '1' ||
            (a == '2' && b <= '6')
        );
    }
};
