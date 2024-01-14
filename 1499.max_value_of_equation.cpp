#include <deque>
#include <utility>
#include <vector>

class Solution {
public:
  int findMaxValueOfEquation(const std::vector<std::vector<int>>& points, const int k) {
    int result = -(1 << 30);
    std::deque<std::pair<int, int>> q;
    for (auto& p: points) {
      int x = p[0], y = p[1];
      while (not q.empty() and x - q.front().first > k) q.pop_front();
      if (not q.empty()) result = std::max(result, x + y + q.front().second - q.front().first);
      while (not q.empty() and y - x >= q.back().second - q.back().first) q.pop_back();
      q.emplace_back(x, y);
    }
    return result;
  }
};
