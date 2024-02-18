#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>

class Solution {
public:
  auto largestPerimeter(const std::vector<int>& nums) {
    std::priority_queue q(nums.begin(), nums.end());
    long long sum = std::reduce(nums.cbegin(), nums.cend(), 0LL);
    while (q.size() > 2) {
      const auto t = q.top();
      if (sum - t > t) return sum;
      q.pop();
      sum -= t;
    }
    return -1LL;
  }

  long long largestPerimeter(std::vector<int>& nums) {
    std::ranges::sort(nums);
    const auto n = nums.size();
    std::vector s(n + 1, 0LL);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + nums[i - 1];
    long long result = -1;
    for (int k = 3; k <= n; ++k)
      if (s[k - 1] > nums[k - 1]) result = std::max(result, s[k]);

    return result;
  }
};
