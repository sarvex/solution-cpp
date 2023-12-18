#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
public:
  auto jump(vector<int> &nums) {
    int result = 0, jump = 0, last = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      jump = max(jump, i + nums[i]);
      if (last == i) {
        ++result;
        last = jump;
      }
    }
    return result;
  }
};
