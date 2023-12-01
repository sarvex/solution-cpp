class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                for (char c : "abc") {
                    if ((i and s[i - 1] == c) or (i + 1 < n and s[i + 1] == c)) {
                        continue;
                    }
                    s[i] = c;
                    break;
                }
            }
        }
        return s;
    }
};