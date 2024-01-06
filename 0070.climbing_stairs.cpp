class Solution {
public:
  auto climbStairs(const int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
      const int c = a + b;
      a = b;
      b = c;
    }
    return b;
  }
};
