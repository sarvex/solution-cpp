#include <algorithm>
#include <unordered_map>
#include <vector>

using std::sort;
using std::unordered_map;
using std::vector;

class Solution {
public:
  auto threeSumFast(vector<int> &nums) {
    vector<vector<int>> result;
    const auto n = nums.size();
    if (n < 3)
      return result;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2 and nums[i] <= 0; ++i) {
      if (i and nums[i] == nums[i - 1])
        continue;

      int k = n - 1;
      for (int j = i + 1; j < k;) {
        if (const int x = nums[i] + nums[j] + nums[k]; x < 0) {
          ++j;
        } else if (x > 0) {
          --k;
        } else {
          result.push_back({nums[i], nums[j++], nums[k--]});
          while (j < k and nums[j] == nums[j - 1])
            ++j;
          while (j < k and nums[k] == nums[k + 1])
            --k;
        }
      }
    }
    return result;
  }

  auto threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    const auto n = nums.size();
    if (n < 3)
      return {};

    sort(nums.begin(), nums.end());
    if (nums[0] > 0)
      return {};

    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
      map[nums[i]] = i;
    }

    for (int i = 0; i < n - 2; ++i) {
      if (nums[i] > 0)
        break;
      for (int j = i + 1; j < n - 1; ++j) {
        int target = -1 * (nums[i] + nums[j]);
        if (auto search = map.find(target);
            search != map.end() && search->second > j) {
          result.push_back({nums[i], nums[j], target});
        }
        j = map.find(nums[j])->second;
      }
      i = map.find(nums[i])->second;
    }
    return result;
  }
};
