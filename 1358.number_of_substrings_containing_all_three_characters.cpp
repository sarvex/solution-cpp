#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
  int numberOfSubstrings(const std::string& s) {
    const int n = static_cast<int>(s.size());
    std::vector d{ -1, -1, -1 };
    int result = 0;
    for (int i = 0; i < n; ++i) {
      d[s[i] - 'a'] = i;
      result += std::min({ d[0], d[1], d[2] }) + 1;
    }
    return result;
  }
};
