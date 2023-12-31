#include <cmath>

class Solution {
public:
  int integerBreak(int n) {
    if (n < 4) return n - 1;
    switch ( n % 3) {
      case 1: return std::pow(3, n / 3 - 1) * 4;
      case 2: return std::pow(3, n / 3) * 2;
      default: return std::pow(3, n / 3);
    }
  }
};
