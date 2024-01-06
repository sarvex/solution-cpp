#include <functional>
#include <vector>

class Solution {
public:
  bool validPartitionFast(const std::vector<int>& nums) {
    std::vector is_valid = { false, nums[0] == nums[1], false, true };
    const int n = nums.size();
    for (int i = 2; i < n; ++i) {
      bool result = false;
      if (nums[i] == nums[i - 1]) {
        result |= is_valid[(i - 2) & 3];
        if (nums[i] == nums[i - 2]) { result |= is_valid[(i - 3) & 3]; }
      } else if (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2) { result |= is_valid[(i - 3) & 3]; }
      is_valid[i & 3] = result;
    }

    return is_valid[(n - 1) & 3];
  }

  bool validPartition(const std::vector<int>& nums) {
    const int n = nums.size();

    std::vector f(n, -1);
    std::function<bool(int)> partition = [&](const int i) {
      if (i == n) return true;
      if (f[i] != -1) return f[i] == 1;
      bool result = false;
      if (i < n - 1 and nums[i] == nums[i + 1]) result = partition(i + 2);
      if (i < n - 2 and nums[i] == nums[i + 1] and nums[i + 1] == nums[i + 2]) result = result or partition(i + 3);
      if (i < n - 2 and nums[i + 1] - nums[i] == 1 and nums[i + 2] - nums[i + 1] == 1)
        result = result or partition(i + 3);
      f[i] = result ? 1 : 0;
      return result;
    };
    return partition(0);
  }
};
