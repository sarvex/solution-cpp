class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> ans(m, -1);
        for (int j = 0; j < m; ++j) {
            int t = queries[j][0], i = queries[j][1];
            t %= (n * 2);
            if (t < n and i < n - t) {
                ans[j] = nums[i + t];
            } else if (t > n and i < t - n) {
                ans[j] = nums[i];
            }
        }
        return ans;
    }
};