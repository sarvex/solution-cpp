#include <algorithm>
#include <vector>

using std::vector;
using std::ranges::sort;

class Solution {
public:
  auto threeSum(vector<int>& nums) {
    sort(nums);
    vector<vector<int>> result;
    const int n = nums.size();
    for (int i = 0; i < n - 2 and nums[i] <= 0; ++i) {
      if (i and nums[i] == nums[i - 1]) {
        continue;
      }
      int j = i + 1, k = n - 1;
      while (j < k) {
        if (const int x = nums[i] + nums[j] + nums[k]; x < 0) {
          ++j;
        } else if (x > 0) {
          --k;
        } else {
          result.push_back({nums[i], nums[j++], nums[k--]});
          while (j < k and nums[j] == nums[j - 1]) {
            ++j;
          }
          while (j < k and nums[k] == nums[k + 1]) {
            --k;
          }
        }
      }
    }
    return result;
  }
};
