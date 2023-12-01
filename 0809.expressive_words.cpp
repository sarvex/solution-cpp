class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        auto check = [](string& s, string& t) -> int {
            int m = s.size(), n = t.size();
            if (n > m) return 0;
            int i = 0, j = 0;
            while (i < m and j < n) {
                if (s[i] != t[j]) return 0;
                int k = i;
                while (k < m and s[k] == s[i]) ++k;
                int c1 = k - i;
                i = k, k = j;
                while (k < n and t[k] == t[j]) ++k;
                int c2 = k - j;
                j = k;
                if (c1 < c2 or (c1 < 3 and c1 != c2)) return 0;
            }
            return i == m and j == n;
        };

        int ans = 0;
        for (string& t : words) ans += check(s, t);
        return ans;
    }
};