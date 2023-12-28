class Solution {
public:
    int result;
    unordered_map<int, int> mp;

    int pathSum(vector<int>& nums) {
        result = 0;
        mp.clear();
        for (int num : nums) mp[num / 10] = num % 10;
        dfs(11, 0);
        return result;
    }

    void dfs(int node, int t) {
        if (not mp.count(node)) return;
        t += mp[node];
        int d = node / 10, p = node % 10;
        int l = (d + 1) * 10 + (p * 2) - 1;
        int r = l + 1;
        if (not mp.count(l) and not mp.count(r)) {
            result += t;
            return;
        }
        dfs(l, t);
        dfs(r, t);
    }
};