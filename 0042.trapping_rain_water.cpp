#include <algorithm>
#include <vector>

class Solution {
public:
  auto trap(const std::vector<int>& height) {
    const int n = height.size();
    std::vector left(n, 0), right(n, 0);
    left[0] = height[0];
    right[n - 1] = height[n - 1];
    for (int i = 1; i < n; ++i) {
      left[i] = std::max(left[i - 1], height[i]);
      right[n - i - 1] = std::max(right[n - i], height[n - i - 1]);
    }
    int result = 0;
    for (int i = 0; i < n; ++i) { result += std::min(left[i], right[i]) - height[i]; }
    return result;
  }
};
