#include <algorithm>
#include <execution>
#include <string>

using std::string;
using std::execution::par;

class Solution {
public:
  int longestValidParentheses(string s) {
    int n = s.size();
    int f[n + 1];
    memset(f, 0, sizeof(f));
    for (int i = 2; i <= n; ++i) {
      if (s[i - 1] == ')') {
        if (s[i - 2] == '(') { f[i] = f[i - 2] + 2; } else {
          int j = i - f[i - 1] - 1;
          if (j and s[j - 1] == '(') { f[i] = f[i - 1] + 2 + f[j - 1]; }
        }
      }
    }
    return *std::max_element(par, f, f + n + 1);
  }
};
