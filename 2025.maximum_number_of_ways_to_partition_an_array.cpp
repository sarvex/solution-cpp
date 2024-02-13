#include <unordered_map>
#include <vector>

class Solution {
public:
  auto waysToPartition(const std::vector<int>& nums, const int k) {
    const auto n = nums.size();
    std::vector s(n, 0LL);
    s[0] = nums[0];
    std::unordered_map<long long, int> right;
    for (int i = 0; i < n - 1; ++i) {
      right[s[i]]++;
      s[i + 1] = s[i] + nums[i + 1];
    }

    int result = s[n - 1] % 2 == 0 ? right[s[n - 1] / 2] : 0;
    std::unordered_map<long long, int> left;
    for (int i = 0; i < n; ++i) {
      if (const int d = k - nums[i]; (s[n - 1] + d) % 2 == 0) {
        int t = left[(s[n - 1] + d) / 2] + right[(s[n - 1] - d) / 2];
        result = std::max(result, t);
      }
      left[s[i]]++;
      right[s[i]]--;
    }
    return result;
  }
};
