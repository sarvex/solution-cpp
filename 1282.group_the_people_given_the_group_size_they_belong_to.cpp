#include <vector>

class Solution {
public:
  auto groupThePeople(const std::vector<int>& groupSizes) {
    const auto n = groupSizes.size();
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < n; ++i) g[groupSizes[i]].push_back(i);
    std::vector<std::vector<int>> result;
    for (int i = 0; i < g.size(); ++i) {
      for (int j = 0; j < g[i].size(); j += i) {
        std::vector t(g[i].begin() + j, g[i].begin() + j + i);
        result.push_back(t);
      }
    }
    return result;
  }
};
