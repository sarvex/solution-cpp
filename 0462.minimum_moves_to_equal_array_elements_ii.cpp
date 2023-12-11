#include <algorithm>
#include <execution>
#include <functional>
#include <numeric>
#include <vector>

using std::nth_element;
using std::vector;
using std::execution::par;

class Solution {
public:
  auto minMoves2(vector<int> &nums) {
    const auto mid = nums.begin() + nums.size() / 2;
    nth_element(par, nums.begin(), mid, nums.end());
    const auto median = *mid;
    return transform_reduce(
        par, nums.cbegin(), nums.cend(), 0L, std::plus{},
        [median](auto value) { return abs(value - median); });
  }
};
