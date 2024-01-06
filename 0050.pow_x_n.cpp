#include <cstdint>

class Solution {
public:
  auto myPowFast(const double x, const int n) {
    if (n == 0) return 1;
    double base = n < 0 ? 1/x : x;
    int64_t power = n < 0 ? -static_cast<int64_t>(n) : n;

    double result = 1;
    for (; power; power >>= 1) {
      if (power & 1) result *= base;
      base *= base;
    }

    return result;
  }

  auto myPow(const double x, const int n) {
    auto qpow = [](double a, uint64_t n) {
      double ans = 1;
      for (; n; n >>= 1) {
        if (n & 1) ans *= a;
        a *= a;
      }
      return ans;
    };
    return n >= 0 ? qpow(x, n) : 1 / qpow(x, -static_cast<uint64_t>(n));
  }
};
