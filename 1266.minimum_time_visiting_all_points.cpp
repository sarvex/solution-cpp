#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
public:
  auto minTimeToVisitAllPoints(const vector<vector<int>>& points) {
    int result = 0;
    for (auto i = 1; i < points.size(); ++i) {
      const auto dx = abs(points[i][0] - points[i - 1][0]);
      const auto dy = abs(points[i][1] - points[i - 1][1]);
      result += max(dx, dy);
    }
    return result;
  }
};
