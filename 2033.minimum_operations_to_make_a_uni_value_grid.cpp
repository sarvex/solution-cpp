#include <algorithm>
#include <execution>
#include <functional>
#include <vector>

using std::any_of;
using std::nth_element;
using std::transform_reduce;
using std::vector;
using std::execution::par;

class Solution {
public:
  auto minOperations(const vector<vector<int>> &grid, const int x) -> int {
    const auto mod = grid[0][0] % x;
    vector<int> nums;

    for (auto &row : grid) {
      if (any_of(par, row.cbegin(), row.cend(),
                 [&](int value) { return (value - mod) % x; }))
        return -1;
      nums.insert(nums.end(), row.cbegin(), row.cend());
    }

    const auto mid = nums.begin() + nums.size() / 2;
    nth_element(par, nums.begin(), mid, nums.end());
    const auto median = *mid;
    return transform_reduce(
        par, nums.cbegin(), nums.cend(), 0L, std::plus{},
        [&](const auto value) { return abs(value - median) / x; });
  }
};
