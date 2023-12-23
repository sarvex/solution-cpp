#include <string>
#include <vector>

class Solution {
public:
  auto longestCommonPrefix(const std::vector<std::string>& strs) -> string{
    const int m = strs.size(), n = strs[0].size();
    if (m == 0 or n == 0) return "";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) { if (strs[j].size() <= i or strs[j][i] != strs[0][i]) return strs[0].substr(0, i); }
    }
    return strs[0];
  }
};
