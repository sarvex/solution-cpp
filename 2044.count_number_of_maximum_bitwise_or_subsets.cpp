class Solution {
public:
    int mx;
    int result;
    vector<int> nums;

    int countMaxOrSubsets(vector<int>& nums) {
        this->nums = nums;
        mx = 0;
        result = 0;
        for (int x : nums) mx |= x;
        dfs(0, 0);
        return result;
    }

    void dfs(int i, int t) {
        if (i == nums.size()) {
            if (t == mx) ++result;
            return;
        }
        dfs(i + 1, t);
        dfs(i + 1, t | nums[i]);
    }
};