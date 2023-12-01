class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size(), n = abbr.size();
        int i = 0, j = 0, x = 0;
        for (; i < m and j < n; ++j) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0' and x == 0) {
                    return false;
                }
                x = x * 10 + (abbr[j] - '0');
            } else {
                i += x;
                x = 0;
                if (i >= m or word[i] != abbr[j]) {
                    return false;
                }
                ++i;
            }
        }
        return i + x == m and j == n;
    }
};