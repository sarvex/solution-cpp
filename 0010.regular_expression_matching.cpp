#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  static auto isMatch(const std::string& s, const std::string& p) {
    const int m = s.length();
    const int n = p.length();
    vector result(m + 1, vector<bool>(n + 1));
    result[0][0] = true;

    auto match = [&](const int i, const int j) { return j >= 0 && p[j] == '.' || s[i] == p[j]; };

    for (int j = 0; j < n; ++j)
      if (p[j] == '*' && result[0][j - 1])
        result[0][j + 1] = true;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (p[j] == '*') {
          result[i + 1][j + 1] = result[i + 1][j - 1] || (match(i, j - 1) && result[i][j + 1]);
        } else if (match(i, j)) {
          result[i + 1][j + 1] = result[i][j];
        }

    return result[m][n];
  }
};
