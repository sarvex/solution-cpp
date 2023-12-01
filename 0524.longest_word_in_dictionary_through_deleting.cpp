class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for (string& a : dictionary)
            if (check(s, a) and (ans.size() < a.size() or (ans.size() == a.size() and a < ans)))
                ans = a;
        return ans;
    }

    bool check(string& a, string& b) {
        int m = a.size(), n = b.size();
        int i = 0, j = 0;
        while (i < m and j < n) {
            if (a[i] == b[j]) ++j;
            ++i;
        }
        return j == n;
    }
};