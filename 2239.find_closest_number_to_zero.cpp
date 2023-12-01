class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = 0, d = 1 << 30;
        for (int x : nums) {
            int y = abs(x);
            if (y < d or (y == d and x > ans)) {
                ans = x;
                d = y;
            }
        }
        return ans;
    }
};