#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
  auto combinationSum(const std::vector<int>& candidates, int target) {
    const int n = candidates.size();
    sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> result;
    std::vector<int> integers;

    std::function<void(int, int)> sum = [&](const int i, const int s) {
      if (s == 0) {
        result.emplace_back(integers);
        return;
      }
      if (i >= n or s < candidates[i]) return;
      sum(i + 1, s);
      integers.push_back(candidates[i]);
      sum(i, s - candidates[i]);
      integers.pop_back();
    };
    sum(0, target);
    return result;
  }
};
