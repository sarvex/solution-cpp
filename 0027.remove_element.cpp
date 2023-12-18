#include <algorithm>
#include <vector>

using std::ranges::remove;
using std::vector;

class Solution {
public:
  auto removeElement(vector<int> &nums, const int val) {
    nums.erase(remove(nums, val).begin(), nums.end());
    return nums.size();
  }
};
