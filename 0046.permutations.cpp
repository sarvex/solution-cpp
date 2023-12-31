#include <functional>
#include <vector>

class Solution {
public:
    auto permuteFast(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    const int n = nums.size();

    std::function<void(int)> solve = [&](const int index) {
      if (index >= n) {
        result.push_back(nums);
        return;
      }

      for (int i = index; i < n; i++) {
        std::swap(nums[i], nums[index]);
        solve(index + 1);
        std::swap(nums[i], nums[index]);
      }
    };

    solve(0);
    return result;
  }

  auto permute(const std::vector<int>& nums) {
    const int n = nums.size();
    std::vector<std::vector<int>> result;
    std::vector<int> integers(n);
    std::vector<bool> seen(n);
    std::function<void(int)> dfs = [&](const int i) {
      if (i == n) {
        result.emplace_back(integers);
        return;
      }
      for (int j = 0; j < n; ++j) {
        if (not seen[j]) {
          seen[j] = true;
          integers[i] = nums[j];
          dfs(i + 1);
          seen[j] = false;
        }
      }
    };
    dfs(0);
    return result;
  }
};
