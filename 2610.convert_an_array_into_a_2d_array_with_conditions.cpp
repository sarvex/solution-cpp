#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> findMatrix(const std::vector<int>& nums) {
    const int n = nums.size();
    std::vector<std::vector<int>> result;
    std::vector<int> count(n + 1);
    for (auto& x: nums) { ++count[x]; }
    for (int x = 1; x <= n; ++x) {
      const int v = count[x];
      if (result.size() <= v) result.resize(v);
      for (int j = 0; j < v; ++j) {
        result[j].push_back(x);
      }
    }
    return result;
  }
};
