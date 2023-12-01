class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = 0, mx = 0, last = 0;
        for (auto& log : logs) {
            int uid = log[0], t = log[1];
            t -= last;
            if (mx < t or (mx == t and ans > uid)) {
                mx = t;
                ans = uid;
            }
            last += t;
        }
        return ans;
    }
};