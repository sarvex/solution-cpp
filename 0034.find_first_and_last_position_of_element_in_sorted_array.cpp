#include <algorithm>
#include <vector>

using std::lower_bound;
using std::upper_bound;
using std::vector;

class Solution {
public:
  auto searchRange(const vector<int> &nums, const int target) -> vector<int> {
    int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int r = upper_bound(nums.begin() + l, nums.end(), target) - nums.begin();
    if (l == r)
      return {-1, -1};
    return {l, r - 1};
  }
};
