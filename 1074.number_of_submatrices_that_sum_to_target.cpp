#include <functional>
#include <vector>

class Solution {
public:
  auto numSubmatrixSumTargetFast(const std::vector<std::vector<int>>& matrix, const int target) {
    const auto m = matrix.size(), n = matrix[0].size();
    int result = 0;
    for (int l = 0; l < n; ++l) {
      std::vector sums(105, 0);
      for (int r = l; r < n; r++) {
        for (int i = 0; i < m; i++) sums[i] += matrix[i][r];
        for (int i = 0; i < m; i++) {
          int sum = 0;
          for (int j = i; j < m; j++) {
            sum += sums[j];
            if (sum == target) result++;
          }
        }
      }
    }
    return result;
  }

  auto numSubmatrixSumTarget(const std::vector<std::vector<int>>& matrix, const int target) {
    const auto m = matrix.size(), n = matrix[0].size();
    int result = 0;

    const std::function<int(std::vector<int>)> f = [&](const std::vector<int>& nums) {
      std::unordered_map<int, int> d { { 0, 1 } };
      int count = 0, sum = 0;
      for (auto& num: nums) {
        sum += num;
        if (d.contains(sum - target)) count += d[sum - target];
        ++d[sum];
      }
      return count;
    };

    for (int i = 0; i < m; ++i) {
      std::vector<int> col(n);
      for (int j = i; j < m; ++j) {
        for (int k = 0; k < n; ++k) col[k] += matrix[j][k];
        result += f(col);
      }
    }
    return result;
  }
};
