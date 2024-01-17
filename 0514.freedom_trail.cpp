#include <limits>
#include <string>
#include <vector>

class Solution {
public:
  auto findRotateSteps(const std::string& ring, const std::string& key) {
    const auto m = static_cast<int>(key.size()), n = static_cast<int>(ring.size());
    constexpr auto inf = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> pos(26);
    for (int j = 0; j < n; ++j) { pos[ring[j] - 'a'].push_back(j); }
    std::vector table(m, std::vector(n, inf));
    for (int j: pos[key[0] - 'a']) { table[0][j] = std::min(j, n - j) + 1; }
    for (int i = 1; i < m; ++i) {
      for (int j: pos[key[i] - 'a']) {
        for (int k: pos[key[i - 1] - 'a']) {
          table[i][j] = std::min(table[i][j], table[i - 1][k] + std::min(std::abs(j - k), n - std::abs(j - k)) + 1);
        }
      }
    }
    int result = inf;
    for (int j: pos[key[m - 1] - 'a']) result = std::min(result, table[m - 1][j]);
    return result;
  }
};
