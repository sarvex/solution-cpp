#include <string>

class Solution {
public:
  auto isNumber(const std::string& s) {
    const int n = s.size();
    int i = 0;
    if (s[i] == '+' or s[i] == '-')
      ++i;
    if (i == n)
      return false;
    if (s[i] == '.' and (i + 1 == n or s[i + 1] == 'e' or s[i + 1] == 'E'))
      return false;
    int dot = 0, e = 0;
    for (int j = i; j < n; ++j) {
      if (s[j] == '.') {
        if (e or dot)
          return false;
        ++dot;
      } else if (s[j] == 'e' or s[j] == 'E') {
        if (e or j == i or j == n - 1)
          return false;
        ++e;
        if (s[j + 1] == '+' or s[j + 1] == '-') {
          if (++j == n - 1)
            return false;
        }
      } else if (s[j] < '0' or s[j] > '9')
        return false;
    }
    return true;
  }
};
