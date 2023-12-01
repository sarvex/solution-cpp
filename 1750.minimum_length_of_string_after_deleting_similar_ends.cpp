class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j and s[i] == s[j]) {
            while (i + 1 < j and s[i] == s[i + 1]) {
                ++i;
            }
            while (i < j - 1 and s[j] == s[j - 1]) {
                --j;
            }
            ++i;
            --j;
        }
        return max(0, j - i + 1);
    }
};