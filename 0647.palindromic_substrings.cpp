#include <string>

class Solution {
public:
  int countSubstrings(const std::string& s) {
    int result = 0;
    const auto n = s.size(), l = s.size() * 2 - 1;
    for (int k = 0; k < l; ++k) {
      int i = k / 2, j = (k + 1) / 2;
      while (~i and j < n and s[i] == s[j]) {
        ++result;
        --i;
        ++j;
      }
    }
    return result;
  }
};
