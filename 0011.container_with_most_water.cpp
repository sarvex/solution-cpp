#include <vector>

class Solution {
public:
  static int maxArea(const std::vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int result = 0;

    while (i < j) {
      int t = std::min(height[i], height[j]) * (j - i);
      result = std::max(result, t);
      if (height[i] < height[j]) {
        ++i;
      } else {
        --j;
      }
    }
    return result;
  }
};
