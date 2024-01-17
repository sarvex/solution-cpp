#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  auto findWinners(const std::vector<std::vector<int>>& matches) {
    std::unordered_map<int, int> count;
    for (auto& m: matches) {
      if (const int a = m[0]; ! count.contains(a)) count[a] = 0;
      ++count[m[1]];
    }
    std::vector<std::vector<int>> result(2);
    for (auto& [u, v]: count) { if (v < 2) result[v].push_back(u); }
    std::ranges::sort(result[0]);
    std::ranges::sort(result[1]);
    return result;
  }
};
