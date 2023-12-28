class Solution {
public:
    unordered_set<string> vis;
    string s;
    int result = 1;

    int maxUniqueSplit(string s) {
        this->s = s;
        dfs(0, 0);
        return result;
    }

    void dfs(int i, int t) {
        if (i >= s.size()) {
            result = max(result, t);
            return;
        }
        for (int j = i + 1; j <= s.size(); ++j) {
            string x = s.substr(i, j - i);
            if (!vis.count(x)) {
                vis.insert(x);
                dfs(j, t + 1);
                vis.erase(x);
            }
        }
    }
};