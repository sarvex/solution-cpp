#include <algorithm>
#include <string>

using std::min;
using std::string;

class Solution {
public:
  auto findMinimumOperations(string s1, string s2, string s3) -> int {
    int s = s1.size() + s2.size() + s3.size();
    int n = min({s1.size(), s2.size(), s3.size()});
    for (int i = 0; i < n; ++i) {
      if (!(s1[i] == s2[i] and s2[i] == s3[i])) {
        return i == 0 ? -1 : s - 3 * i;
      }
    }
    return s - 3 * n;
  }
};
