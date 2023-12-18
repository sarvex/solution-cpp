#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>

using std::function;
using std::ranges::sort;
using std::vector;

class Solution {
public:
  vector<vector<int>> fourSumFast(vector<int>& nums, int target) {
    vector<vector<int>> result;
    vector<int> path;
    sort(nums);

    function<void(int64_t, int64_t, int, int)>
        n_sum = [&](const int64_t n, const int64_t target, int l, int r) {
          if (r - l + 1 < n or target < nums[l] * n or target > nums[r] * n)
            return;
          if (n == 2) {
            while (l < r) {
              if (const int sum = nums[l] + nums[r]; sum < target)
                ++l;
              else if (sum > target)
                --r;
              else {
                path.push_back(nums[l++]);
                path.push_back(nums[r--]);
                result.push_back(path);
                path.pop_back();
                path.pop_back();
                while (l < r and nums[l] == nums[l - 1])
                  ++l;
                while (l < r and nums[r] == nums[r + 1])
                  --r;
              }
            }
            return;
          }

          for (int i = l; i <= r; ++i) {
            if (i > l and nums[i] == nums[i - 1])
              continue;
            path.push_back(nums[i]);
            n_sum(n - 1, target - nums[i], i + 1, r);
            path.pop_back();
          }
        };

    n_sum(4, target, 0, nums.size() - 1);
    return result;
  }

  auto fourSum(vector<int>& nums, const int target) {
    const int n = nums.size();
    vector<vector<int>> result;
    if (n < 4) { return result; }
    sort(nums.begin(), nums.end());
    for (auto i = 0; i < n - 3; ++i) {
      if (i and nums[i] == nums[i - 1]) { continue; }
      for (auto j = i + 1; j < n - 2; ++j) {
        if (j > i + 1 and nums[j] == nums[j - 1]) { continue; }
        int k = j + 1, l = n - 1;
        while (k < l) {
          if (const int x = (nums[i]) + nums[j] + nums[k] + nums[l];
            x < target) { ++k; } else if (x > target) { --l; } else {
            result.push_back({ nums[i], nums[j], nums[k++], nums[l--] });
            while (k < l and nums[k] == nums[k - 1]) { ++k; }
            while (k < l and nums[l] == nums[l + 1]) { --l; }
          }
        }
      }
    }
    return result;
  }
};
