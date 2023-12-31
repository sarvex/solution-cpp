#include <functional>
#include <vector>

class Solution {
public:
  auto combine(const int n, const int k) {
    std::vector<std::vector<int>> result;
    std::vector<int> integers;
    std::function<void(int)> dfs = [&](int i) {
      if (integers.size() == k) {
        result.emplace_back(integers);
        return;
      }
      if (i > n) return;
      integers.emplace_back(i);
      dfs(i + 1);
      integers.pop_back();
      dfs(i + 1);
    };
    dfs(1);
    return result;
  }
};
