#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSatisfaction(std::vector<int>& satisfaction) {
    sort(satisfaction.rbegin(), satisfaction.rend());
    int result = 0, sum = 0;
    for (const auto& elem: satisfaction) {
      sum += elem;
      if (sum <= 0) break;
      result += sum;
    }
    return result;
  }
};
