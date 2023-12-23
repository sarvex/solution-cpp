#include <vector>

class Solution {
public:
  auto twoSum(std::vector<int>& numbers, int target) {
    for (int i = 0, j = numbers.size() - 1;;) {
      const int x = numbers[i] + numbers[j];
      if (x == target) { return { i + 1, j + 1 }; }
      if (x < target) { ++i; } else { --j; }
    }
  }
};
