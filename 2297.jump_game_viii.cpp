#include <stack>
#include <vector>

class Solution {
public:
  auto minimumCost(const std::vector<int>& nums, const std::vector<int>& costs) {
    const auto n = nums.size();
    std::vector g(n, std::vector<int>());
    std::stack<int> stk;
    for (int i = n - 1; ~i; --i) {
      while (not stk.empty() and nums[stk.top()] < nums[i]) stk.pop();
      if (not stk.empty()) g[i].push_back(stk.top());
      stk.push(i);
    }
    stk = {};
    for (int i = n - 1; ~i; --i) {
      while (! stk.empty() and nums[stk.top()] >= nums[i]) stk.pop();
      if (! stk.empty()) g[i].push_back(stk.top());
      stk.push(i);
    }
    std::vector<long long> f(n, 1e18);
    f[0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j: g[i]) { f[j] = std::min(f[j], f[i] + costs[j]); }
    }
    return f[n - 1];
  }
};
