#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
  int minSteps(const std::string& s, const std::string& t) {
    std::vector count(26, 0);
    for (auto& c : s) ++count[c - 'a'];
    for (auto& c : t) --count[c - 'a'];
    return std::transform_reduce(count.begin(), count.end(), 0, std::plus{}, static_cast<int (*)(int)>(std::abs));
  }
};
