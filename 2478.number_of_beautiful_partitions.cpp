class Solution {
public:
    const int mod = 1e9 + 7;

    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        auto prime = [](char c) {
            return c == '2' or c == '3' or c == '5' or c == '7';
        };
        if (!prime(s[0]) or prime(s[n - 1])) return 0;
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        vector<vector<int>> g(n + 1, vector<int>(k + 1));
        f[0][0] = g[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (i >= minLength and !prime(s[i - 1]) and (i == n or prime(s[i]))) {
                for (int j = 1; j <= k; ++j) {
                    f[i][j] = g[i - minLength][j - 1];
                }
            }
            for (int j = 0; j <= k; ++j) {
                g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
            }
        }
        return f[n][k];
    }
};