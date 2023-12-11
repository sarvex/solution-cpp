#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
public:
  auto jump(vector<int> &nums) {
    int ans = 0, mx = 0, last = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      mx = max(mx, i + nums[i]);
      if (last == i) {
        ++ans;
        last = mx;
      }
    }
    return ans;
  }
};
