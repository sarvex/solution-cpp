#include <functional>
#include <unordered_map>
#include <vector>

class Solution {
public:
  auto canCross(const std::vector<int>& stones) {
    const auto n = stones.size();
    std::vector f(n, std::vector(n, -1));
    std::unordered_map<int, int> pos;
    for (int i = 0; i < n; ++i) pos[stones[i]] = i;
    const std::function<bool(int, int)> search = [&](const int i, const int k) -> bool {
      if (i == n - 1) return true;
      if (f[i][k] != -1) return f[i][k];
      for (int j = k - 1; j <= k + 1; ++j)
        if (j > 0 and pos.contains(stones[i] + j) and search(pos[stones[i] + j], j)) return f[i][k] = true;
      return f[i][k] = false;
    };
    return search(0, 0);
  }
};
