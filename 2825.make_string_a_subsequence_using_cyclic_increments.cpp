class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, n = str2.size();
        for (char c : str1) {
            char d = c == 'z' ? 'a' : c + 1;
            if (i < n and (str2[i] == c or str2[i] == d)) {
                ++i;
            }
        }
        return i == n;
    }
};