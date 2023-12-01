class Solution {
public:
    int a[6];
    int dp[6][2];

    int rotatedDigits(int n) {
        memset(dp, -1, sizeof dp);
        int len = 0;
        while (n) {
            a[++len] = n % 10;
            n /= 10;
        }
        return dfs(len, 0, true);
    }

    int dfs(int pos, int ok, bool limit) {
        if (pos <= 0) {
            return ok;
        }
        if (not limit and dp[pos][ok] != -1) {
            return dp[pos][ok];
        }
        int up = limit ? a[pos] : 9;
        int ans = 0;
        for (int i = 0; i <= up; ++i) {
            if (i == 0 or i == 1 or i == 8) {
                ans += dfs(pos - 1, ok, limit and i == up);
            }
            if (i == 2 or i == 5 or i == 6 or i == 9) {
                ans += dfs(pos - 1, 1, limit and i == up);
            }
        }
        if (not limit) {
            dp[pos][ok] = ans;
        }
        return ans;
    }
};