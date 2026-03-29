class Solution {
public:
    int numDecodings(string s) {
        int n1 = 1, n2 = 1;

        for (int i = 0; i < s.size(); i++) {
            int temp = s[i] != '0' ? n2 : 0;
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
            (a == '2' && '0' <= b && b <= '6')
        );
    }
};
