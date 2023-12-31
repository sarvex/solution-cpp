#include <algorithm>
#include <vector>

using std::reverse;
using std::swap;
using std::vector;

class Solution {
public:
  auto nextPermutation(vector<int> &nums) {
    const int n = nums.size();
    int i = n - 2;
    while (~i and nums[i] >= nums[i + 1]) {
      --i;
    }
    if (~i) {
      for (int j = n - 1; j > i; --j) {
        if (nums[j] > nums[i]) {
          swap(nums[i], nums[j]);
          break;
        }
      }
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};
