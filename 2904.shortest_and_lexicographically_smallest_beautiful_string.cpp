class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0, j = 0, cnt = 0;
        int n = s.size();
        string ans = "";
        while (j < n) {
            cnt += s[j] == '1';
            while (cnt > k or (i < j and s[i] == '0')) {
                cnt -= s[i++] == '1';
            }
            ++j;
            string t = s.substr(i, j - i);
            if (cnt == k and (ans == "" or j - i < ans.size() or (j - i == ans.size() and t < ans))) {
                ans = t;
            }
        }
        return ans;
    }
};