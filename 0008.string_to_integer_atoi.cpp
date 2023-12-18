#include <string>
#include <limits>

using std::string;
using std::numeric_limits;


class Solution {
public:
  auto myAtoi(const string &s) {
    int n = s.size();
    if (0 == n)
      return 0;

    auto i = s.find_first_not_of(' ');
    if (string::npos == i)
      return 0;

    const int sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' or s[i] == '+')
      ++i;

    int64_t result = 0;
    for (; i < s.size() and isdigit(s[i]); ++i) {
      result = result * 10 + s[i] - '0';
      if (result > numeric_limits<int>::max())
        break;
    }

    result *= sign;
    if (result > numeric_limits<int>::max())
      return numeric_limits<int>::max();
    else if (result < numeric_limits<int>::min())
      return numeric_limits<int>::min();
    return result;
  }
};
