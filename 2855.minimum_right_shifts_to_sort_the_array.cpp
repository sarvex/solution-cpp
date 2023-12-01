class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        while (i < n and nums[i - 1] < nums[i]) {
            ++i;
        }
        int k = i + 1;
        while (k < n and nums[k - 1] < nums[k] and nums[k] < nums[0]) {
            ++k;
        }
        return k < n ? -1 : n - i;
    }
};