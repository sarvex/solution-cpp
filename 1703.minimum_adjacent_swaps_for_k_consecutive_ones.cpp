#include <_mingw_stat64.h>
#include <cstdint>
#include <vector>

class Solution {
public:
  int minMovesFast(const std::vector<int>& nums, const int k) {
    const int n = static_cast<int>(nums.size());
    if (n == 1 || k == 1) return 0;

    std::vector<int64_t> x;

#pragma unroll
    for (int i = 0; i < n; i++) if (nums[i]) x.emplace_back(i);

    const int size = static_cast<int>(x.size());
    std::vector prefix(size, 0LL);
    int64_t sum = 0;

#pragma unroll
    for (int i = 0; i < size; i++) {
      sum += x[i];
      prefix[i] = sum;
    }

    const int64_t c = (k / 2) * ((k + 1) / 2);
    int64_t result = prefix[k - 1] - prefix[k / 2 - 1] - prefix[(k - 1) / 2] - c;

    #pragma unroll
    for (int i = 1; i < size - k + 1; i++) {
      int64_t cost = prefix[i + k - 1] - prefix[i + (k / 2) - 1] - prefix[i + (k - 1) / 2] + prefix[i - 1] - c;
      result = std::min(result, cost);
    }

    return static_cast<int>(result);
  }

  int minMoves(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> arr;
    for (int i = 0; i < n; ++i) { if (nums[i]) { arr.push_back(i); } }
    const int m = static_cast<int>(arr.size());
    std::vector s(m + 1, 0L);
    s[0] = 1L;
    for (int i = 0; i < m; ++i) { s[i + 1] = s[i] + arr[i]; }
    int64_t result = 1L << 60;
    const int x = (k + 1) / 2;
    const int y = k - x;
    for (int i = x - 1; i < m - y; ++i) {
      const int j = arr[i];
      const int ls = s[i + 1] - s[i + 1 - x];
      const int rs = s[i + 1 + y] - s[i + 1];
      const int64_t a = (j + j - x + 1L) * x / 2 - ls;
      const int64_t b = rs - (j + 1L + j + y) * y / 2;
      result = std::min(result, a + b);
    }
    return static_cast<int>(result);
  }
};
