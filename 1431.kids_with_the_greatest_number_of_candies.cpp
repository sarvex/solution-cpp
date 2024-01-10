#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<bool> kidsWithCandies(std::vector<int>& candies, const int extraCandies) {
    const int mx = *max_element(candies.cbegin(), candies.cend());
    std::vector<bool> result;
    for (const auto candy: candies) { result.push_back(candy + extraCandies >= mx); }
    return result;
  }
};
