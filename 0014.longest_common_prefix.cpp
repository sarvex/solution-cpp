#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  auto longestCommonPrefix(const vector<string>& strs) {
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
