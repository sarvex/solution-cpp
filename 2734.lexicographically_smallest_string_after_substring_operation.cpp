class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int i = 0;
        while (i < n and s[i] == 'a') {
            ++i;
        }
        if (i == n) {
            s[n - 1] = 'z';
            return s;
        }
        int j = i;
        while (j < n and s[j] != 'a') {
            s[j] = s[j] - 1;
            ++j;
        }
        return s;
    }
};