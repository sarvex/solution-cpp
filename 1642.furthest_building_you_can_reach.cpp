#include <queue>
#include <vector>

class Solution {
public:
  auto furthestBuilding(const std::vector<int>& heights, int bricks, int ladders) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    const int n = static_cast<int>(heights.size());
    for (int i = 0; i < n - 1; ++i) {
      if (const int d = heights[i + 1] - heights[i]; d > 0) {
        q.push(d);
        if (q.size() > ladders) {
          bricks -= q.top();
          q.pop();
          if (bricks < 0) return i;
        }
      }
    }
    return n - 1;
  }
};
