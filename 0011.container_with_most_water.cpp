#include <vector>
#include <algorithm>

class Solution {
public:
  auto maxArea(const std::vector<int>& height) {
    int result = 0;

    for (int i = 0, j = height.size() - 1; i < j;) {
      int t = std::min(height[i], height[j]) * (j - i);
      result = std::max(result, t);
      if (height[i] < height[j]) { ++i; } else { --j; }
    }
    return result;
  }
};
