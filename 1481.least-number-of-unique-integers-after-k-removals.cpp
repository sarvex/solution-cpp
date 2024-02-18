#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  auto findLeastNumOfUniqueInts(const std::vector<int>& arr, int k) {
    std::unordered_map<int, int> cnt;
    for (auto& x: arr) ++cnt[x];
    std::vector<int> nums;
    nums.reserve(cnt.size());
    for (auto& [_, c]: cnt) nums.push_back(c);
    std::ranges::sort(nums);
    for (int i = 0, m = static_cast<int>(nums.size()); i < m; ++i) {
      k -= nums[i];
      if (k < 0) return m - i;
    }
    return 0;
  }
};
