class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> cnt;
        unordered_map<string, int> d;
        int n = ids.size();
        for (int k = 0; k < n; ++k) {
            auto c = creators[k], id = ids[k];
            int v = views[k];
            cnt[c] += v;
            if (!d.count(c) or views[d[c]] < v or (views[d[c]] == v and ids[d[c]] > id)) {
                d[c] = k;
            }
        }
        long long mx = 0;
        for (auto& [_, x] : cnt) {
            mx = max(mx, x);
        }
        vector<vector<string>> ans;
        for (auto& [c, x] : cnt) {
            if (x == mx) {
                ans.push_back({c, ids[d[c]]});
            }
        }
        return ans;
    }
};