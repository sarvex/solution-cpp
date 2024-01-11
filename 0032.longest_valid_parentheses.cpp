#include <algorithm>
#include <execution>
#include <string>

class Solution {
public:
  auto longestValidParentheses(const std::string& s) {
    const int n = s.size();
    std::vector result(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
      if (s[i - 1] == ')') {
        if (s[i - 2] == '(') {
          result[i] = result[i - 2] + 2;
        } else {
          if (const int j = i - result[i - 1] - 1; j and s[j - 1] == '(') result[i] = result[i - 1] + 2 + result[j - 1];
        }
      }
    }
    return *std::max_element(std::execution::par, result.cbegin(), result.cend());
  }
};
