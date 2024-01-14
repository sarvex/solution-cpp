#include <cstdint>
#include <vector>

class Solution {
public:
  int64_t appealSum(const string& s) {
    const int n = s.size();
    int64_t result = 0, t = 0;
    std::vector position(26, -1);
    for (int i = 0; i < n; ++i) {
      const int c = s[i] - 'a';
      t += i - position[c];
      result += t;
      position[c] = i;
    }
    return result;
  }
};
