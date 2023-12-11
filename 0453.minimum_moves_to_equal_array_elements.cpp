#include <algorithm>
#include <execution>
#include <limits>
#include <vector>

using std::execution::par;
using std::min;
using std::numeric_limits;
using std::vector;

class Solution {
public:
    auto minMoves(const vector<int>& nums) {
      const auto min = *min_element(par, nums.cbegin(), nums.cend());
      const auto sum = reduce(par, nums.cbegin(), nums.cend());

      return sum - (min * nums.size());
    }
};
