#include <vector>
#include <numeric>

class Solution {
public:
  int countVowelStrings(const int n) {
    std::vector result{ 1, 1, 1, 1, 1 };
    for (int i = 0; i < n - 1; ++i) {
      int sum = 0;
      for (int j = 0; j < 5; ++j) {
        sum += result[j];
        result[j] = sum;
      }
    }
    return std::reduce(result.cbegin(), result.cend());
  }
};
