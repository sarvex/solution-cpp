class Solution {
public:
    int sumOfMultiples(int n) {
        int ans = 0;
        for (int x = 1; x <= n; ++x) {
            if (x % 3 == 0 or x % 5 == 0 or x % 7 == 0) {
                ans += x;
            }
        }
        return ans;
    }
};