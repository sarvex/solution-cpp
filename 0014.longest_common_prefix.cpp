#include <string>
#include <vector>

class Solution {
public:
  static std::string longestCommonPrefix(std::vector<std::string>& strs) {
    const int n = strs.size();
    for (int i = 0; i < strs[0].size(); ++i) {
      for (int j = 1; j < n; ++j) {
        if (strs[j].size() <= i or strs[j][i] != strs[0][i]) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0];
  }
};
