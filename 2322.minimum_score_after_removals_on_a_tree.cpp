class Solution {
public:
    vector<int> nums;
    int s;
    int s1;
    int n;
    int result = INT_MAX;
    vector<vector<int>> g;

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        g.resize(n, vector<int>());
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for (int& v : nums) s ^= v;
        this->nums = nums;
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                s1 = dfs(i, -1, j);
                dfs2(i, -1, j);
            }
        }
        return result;
    }

    int dfs(int i, int fa, int x) {
        int res = nums[i];
        for (int j : g[i])
            if (j != fa and j != x) res ^= dfs(j, i, x);
        return res;
    }

    int dfs2(int i, int fa, int x) {
        int res = nums[i];
        for (int j : g[i])
            if (j != fa and j != x) {
                int a = dfs2(j, i, x);
                res ^= a;
                int b = s1 ^ a;
                int c = s ^ s1;
                int t = max(max(a, b), c) - min(min(a, b), c);
                result = min(result, t);
            }
        return res;
    }
};