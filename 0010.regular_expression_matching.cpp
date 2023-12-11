#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  static auto isMatch(const std::string& s, const std::string& p) {
    const int m = s.size();
    const int n = p.size();

    bool f[m + 1][n + 1];
    memset(f, false, sizeof f);

    f[0][0] = true;

    for (int i = 0; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
          f[i][j] = f[i][j - 2];
          if (i and (p[j - 2] == '.' or p[j - 2] == s[i - 1])) {
            f[i][j] |= f[i - 1][j];
          }
        } else if (i and (p[j - 1] == '.' or p[j - 1] == s[i - 1])) {
          f[i][j] = f[i - 1][j - 1];
        }
      }
    }
    return f[m][n];
  }
};
