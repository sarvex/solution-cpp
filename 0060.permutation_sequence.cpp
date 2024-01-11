#include <bitset>
#include <sstream>

class Solution {
public:
  auto getPermutation(const int n, int k) {
    std::ostringstream result;
    std::bitset<10> seen;
    for (int i = 0; i < n; ++i) {
      int fact = 1;
      for (int j = 1; j < n - i; ++j)
        fact *= j;
      for (int j = 1; j <= n; ++j) {
        if (seen[j])
          continue;
        if (k > fact)
          k -= fact;
        else {
          result << j;
          seen[j] = true;
          break;
        }
      }
    }
    return result.str();
  }
};
