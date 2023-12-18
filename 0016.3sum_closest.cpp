#include <algorithm>
#include <cmath>
#include <vector>

using std::abs;
using std::ranges::sort;
using std::vector;

class Solution {
public:
  auto threeSumClosest(vector<int> &nums, const int target) {
    sort(nums);
    int result = 1 << 30;
    const auto n = nums.size();
    for (int i = 0; i < n; ++i) {
      int j = i + 1, k = n - 1;
      while (j < k) {
        const int t = nums[i] + nums[j] + nums[k];
        if (t == target)
          return t;
        if (abs(t - target) < abs(result - target))
          result = t;
        if (t > target)
          --k;
        else
          ++j;
      }
    }
    return result;
  }
};
