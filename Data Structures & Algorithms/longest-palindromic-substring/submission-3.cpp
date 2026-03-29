class Solution {
public:
    string longestPalindrome(string s) {
        int center = 0;
        int len = 1;

        for (int i = 0; i < s.size(); i++) {
            for (int j = 1; i-j>=0 && i+j<s.size(); j++) {
                if (s[i-j] == s[i+j]) {
                    if (1+j*2 > len) {
                        center = i;
                        len = 1+j*2;
                    }
                }
                else
                    break;
            }

            for (int j = 0; i-j>=0 && i+j+1 < s.size(); j++) {
                if (s[i-j] == s[i+j+1]) {
                    if ((j+1)*2 > len) {
                        center = i;
                        len = (j+1)*2;
                    }
                } else
                    break;
            }
        }

        cout<<center<<" :c, len: "<<len;

        return s.substr(center-(len-1)/2, len);
    }
};
