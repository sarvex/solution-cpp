class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        auto check = [](string& s, string& t) {
            int m = s.size(), n = t.size();
            int i = 0, j = 0;
            for (; j < n; ++i, ++j) {
                while (i < m and s[i] != t[j] and islower(s[i])) {
                    ++i;
                }
                if (i == m or s[i] != t[j]) {
                    return false;
                }
            }
            while (i < m and islower(s[i])) {
                ++i;
            }
            return i == m;
        };
        for (auto& q : queries) {
            ans.push_back(check(q, pattern));
        }
        return ans;
    }
};