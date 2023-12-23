#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  auto  maxPoints(const std::vector<std::vector<int>>& points) {
    const int n = points.size();
    int result = 1;
    for (int i = 0; i < n; ++i) {
      const int x1 = points[i][0], y1 = points[i][1];
      std::unordered_map<std::string, int> count;
      for (int j = i + 1; j < n; ++j) {
        const int x2 = points[j][0], y2 = points[j][1];
        const int dx = x2 - x1, dy = y2 - y1;
        const int g = std::gcd(dx, dy);
        std::string k = std::to_string(dx / g) + "." + std::to_string(dy / g);
        count[k]++;
        result = std::max(result, count[k] + 1);
      }
    }
    return result;
  }
};
