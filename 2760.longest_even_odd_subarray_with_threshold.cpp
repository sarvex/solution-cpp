class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        for (int l = 0, n = nums.size(); l < n;) {
            if (nums[l] % 2 == 0 and nums[l] <= threshold) {
                int r = l + 1;
                while (r < n and nums[r] % 2 != nums[r - 1] % 2 and nums[r] <= threshold) {
                    ++r;
                }
                ans = max(ans, r - l);
                l = r;
            } else {
                ++l;
            }
        }
        return ans;
    }
};