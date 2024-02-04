#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> sequentialDigits(const int low, const int high) {
    std::vector<int> result;
    for (int i = 1; i < 9; ++i) {
      int x = i;
      for (int j = i + 1; j < 10; ++j) {
        x = x * 10 + j;
        if (x >= low and x <= high) result.push_back(x);
      }
    }
    std::ranges::sort(result);
    return result;
  }
};
