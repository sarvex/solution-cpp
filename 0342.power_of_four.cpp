class Solution {
public:
  static auto isPowerOfFour(const int n) {
    if (n <= 0) { return false; }
    if (n == 1) { return true; }
    return (n & (n - 1)) == 0 and (n & 0xaaaaaaaa) == 0;
  }
};
