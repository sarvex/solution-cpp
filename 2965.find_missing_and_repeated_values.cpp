#include <vector>

class Solution {
public:
  auto findMissingAndRepeatedValues(const std::vector<std::vector<int>>& grid) {
    const auto n = grid.size();
    std::vector<int> count(n * n + 1);
    std::vector<int> result(2);
    for (const auto& row: grid) { for (const auto& num: row) { if (++count[num] == 2) { result[0] = num; } } }
    for (int i = 1;; ++i)
      if (count[i] == 0) {
        result[1] = i;
        return result;
      }
  }
};
