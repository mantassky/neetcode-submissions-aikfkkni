class Solution {
public:
    string encode(vector<string>& strs) {
        string result = "";
        for (int i = 0; i < 100; i++) {
            if (i < strs.size())
                result += int2char(strs[i].length());
            else
                result += int2char(255); // marks the cutoff
        }

        for (string x : strs)
            result += x;

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int start = 100;

        for (int i = 0; i < 100; i++) {
            int str_length = char2int(s[i]);
            if (str_length == 255) break;

            result.push_back(s.substr(start, str_length));
            start += str_length;
        }

        return result;
    }


    unsigned char int2char(int x) {
        return static_cast<unsigned char>(x);
    }

    int char2int(unsigned char x) {
        return static_cast<int>(x);
    }
};