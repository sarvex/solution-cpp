#include <vector>

class Solution {
public:
  std::vector<long long> countOfPairs(const int n, int x, int y) {
    std::vector result(n, 0LL);
    if (x > y) std::swap(x, y);
    for (int i = 1; i <= n; ++i) {
      result[0] += 2;
      --result[std::min(i - 1, abs(i - y) + x)];
      --result[std::min(n - i, abs(i - x) + 1 + n - y)];
      ++result[std::min(abs(i - x), abs(y - i) + 1)];
      ++result[std::min(abs(i - x) + 1, abs(y - i))];
      const auto r = std::max(x - i, 0) + std::max(i - y, 0);
      --result[r + (y - x) / 2];
      --result[r + (y - x + 1) / 2];
    }

    for (int i = 1; i < n; ++i) result[i] += result[i - 1];
    return result;
  }
};
