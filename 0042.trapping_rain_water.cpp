#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
  auto trap(vector<int> &height) {
    int n = height.size();
    int left[n], right[n];
    left[0] = height[0];
    right[n - 1] = height[n - 1];
    for (int i = 1; i < n; ++i) {
      left[i] = max(left[i - 1], height[i]);
      right[n - i - 1] = max(right[n - i], height[n - i - 1]);
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
      result += min(left[i], right[i]) - height[i];
    }
    return result;
  }
};
