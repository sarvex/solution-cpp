#include <vector>
#include <algorithm>

using std::ranges::nth_element;
using std::vector;

class Solution {
public:
  int majorityElementFast(vector<int>& nums) {
    const auto mid = nums.size() / 2;
    nth_element(nums, nums.begin() + mid);
    return nums[mid];
  }

  int majorityElement(const vector<int>& nums) {
    int cnt = 0, m = 0;
    for (const auto& x: nums) {
      if (cnt == 0) {
        m = x;
        cnt = 1;
      } else { cnt += m == x ? 1 : -1; }
    }
    return m;
  }
};
