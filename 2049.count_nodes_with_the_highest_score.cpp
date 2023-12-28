class Solution {
public:
    int result;
    long long maxScore;
    int n;

    int countHighestScoreNodes(vector<int>& parents) {
        result = 0;
        maxScore = 0;
        n = parents.size();
        unordered_map<int, vector<int>> g;
        for (int i = 1; i < n; ++i) g[parents[i]].push_back(i);
        dfs(0, g);
        return result;
    }

    int dfs(int u, unordered_map<int, vector<int>>& g) {
        int size = 1;
        long long score = 1;
        for (int v : g[u]) {
            int t = dfs(v, g);
            size += t;
            score *= t;
        }
        if (u > 0) score *= (n - size);
        if (score > maxScore) {
            maxScore = score;
            result = 1;
        } else if (score == maxScore)
            ++result;
        return size;
    }
};