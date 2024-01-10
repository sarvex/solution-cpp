#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> restoreArray(const std::vector<std::vector<int>>& adjacentPairs) {
    const int n = adjacentPairs.size() + 1;
    std::unordered_map<int, std::vector<int>> g;
    for (auto& e: adjacentPairs) {
      int a = e[0], b = e[1];
      g[a].push_back(b);
      g[b].push_back(a);
    }
    std::vector<int> result(n);
    for (auto& [k, v]: g) {
      if (v.size() == 1) {
        result[0] = k;
        result[1] = v[0];
        break;
      }
    }
    for (int i = 2; i < n; ++i) {
      auto v = g[result[i - 1]];
      result[i] = v[0] == result[i - 2] ? v[1] : v[0];
    }
    return result;
  }
};
