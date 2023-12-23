#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  int maxWidthOfVerticalArea(const std::vector<std::vector<int>>& points) {
    const int n = points.size();
    std::vector<int> nums;
    for (auto& point: points) { nums.push_back(point[0]); }
    int mi = std::numeric_limits<int>::max(), mx = std::numeric_limits<int>::min();
    for (int num: nums) {
      mi = std::min(mi, num);
      mx = std::max(mx, num);
    }
    const int size = std::max(1, (mx - mi) / (n - 1));
    const int count = (mx - mi) / size + 1;
    std::vector<std::pair<int, int>> buckets(
        count,
        { std::numeric_limits<int>::max(), std::numeric_limits<int>::min() });
    for (int num: nums) {
      const int i = (num - mi) / size;
      buckets[i].first = std::min(buckets[i].first, num);
      buckets[i].second = std::max(buckets[i].second, num);
    }
    int result = 0;
    int prev = std::numeric_limits<int>::max();
    for (auto [curmin, curmax]: buckets) {
      if (curmin > curmax) continue;
      result = std::max(result, curmin - prev);
      prev = curmax;
    }
    return result;
  }
};
