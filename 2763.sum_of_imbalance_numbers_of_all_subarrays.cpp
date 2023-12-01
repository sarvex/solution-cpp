class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            multiset<int> s;
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                auto it = s.lower_bound(nums[j]);
                if (it != s.end() and *it - nums[j] > 1) {
                    ++cnt;
                }
                if (it != s.begin() and nums[j] - *prev(it) > 1) {
                    ++cnt;
                }
                if (it != s.end() and it != s.begin() and *it - *prev(it) > 1) {
                    --cnt;
                }
                s.insert(nums[j]);
                ans += cnt;
            }
        }
        return ans;
    }
};