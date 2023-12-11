#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  auto longestPalindrome(const string& s) {
    const int n = s.size();

    vector f(n, std::vector(n, true));
    int k = 0, mx = 1;
    for (int i = n - 2; ~i; --i) {
      for (int j = i + 1; j < n; ++j) {
        f[i][j] = false;
        if (s[i] == s[j]) {
          f[i][j] = f[i + 1][j - 1];
          if (f[i][j] and mx < j - i + 1) {
            mx = j - i + 1;
            k = i;
          }
        }
      }
    }
    return s.substr(k, mx);
  }
};
