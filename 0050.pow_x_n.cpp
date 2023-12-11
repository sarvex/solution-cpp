#include <cstdint>

class Solution {
public:
  auto myPow(double x, int n) {
    auto qpow = [](double a, uint64_t n) {
      double ans = 1;
      for (; n; n >>= 1) {
        if (n & 1) {
          ans *= a;
        }
        a *= a;
      }
      return ans;
    };
    return n >= 0 ? qpow(x, n) : 1 / qpow(x, -static_cast<uint64_t>(n));
  }
};
