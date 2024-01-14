#include <queue>
#include <vector>

class Solution {
public:
  auto minStoneSum(const std::vector<int>& piles, const int k) {
    std::priority_queue que{piles.cbegin(), piles.cend()};
    for (auto i = k; i; --i) {
      const int p = que.top();
      que.pop();
      que.push((p + 1) >> 1);
    }
    int result = 0;
    while (not que.empty()) {
      result += que.top();
      que.pop();
    }
    return result;
  }
};
