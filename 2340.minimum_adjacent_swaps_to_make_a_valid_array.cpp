class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[i] or (nums[k] == nums[i] and k < i)) {
                i = k;
            }
            if (nums[k] > nums[j] or (nums[k] == nums[j] and k > j)) {
                j = k;
            }
        }
        if (i == j) {
            return 0;
        }
        return i + n - 1 - j - (i > j);
    }
};