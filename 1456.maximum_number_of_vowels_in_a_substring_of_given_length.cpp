class Solution {
public:
    int maxVowels(string s, int k) {
        int t = 0, n = s.size();
        for (int i = 0; i < k; ++i) t += isVowel(s[i]);
        int ans = t;
        for (int i = k; i < n; ++i) {
            t += isVowel(s[i]);
            t -= isVowel(s[i - k]);
            ans = max(ans, t);
        }
        return ans;
    }

    bool isVowel(char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
};