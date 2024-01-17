#include <numeric>
#include <vector>
#include <cstdlib>

class Solution {
public:
  auto findMinMoves(const std::vector<int>& machines) {
    const auto n = static_cast<int>(machines.size());
    int s = std::reduce(machines.begin(), machines.end());
    if (s % n) return -1;
    const int k = s / n;
    s = 0;
    int result = 0;
    for (int x: machines) {
      x -= k;
      s += x;
      result = std::max({ result, std::abs(s), x });
    }
    return result;
  }
};
