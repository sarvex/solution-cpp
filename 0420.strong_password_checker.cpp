#include <algorithm>
#include <string>

class Solution {
public:
  int strongPasswordChecker(const std::string& password) {
    const int n = password.size();

    int lower = 0, upper = 0, digit = 0;
    for (auto& ch: password) {
      if (islower(ch)) lower = 1;
      else if (isupper(ch)) upper = 1;
      else if (isdigit(ch)) digit = 1;
    }
    const int types = lower + upper + digit;
    if (n < 6) return std::max(6 - n, 3 - types);

    if (n <= 20) {
      int replace = 0, cnt = 0;
      char prev = '~';
      for (auto& curr: password) {
        if (curr == prev)
          ++cnt;
        else {
          replace += cnt / 3;
          cnt = 1;
          prev = curr;
        }
      }
      replace += cnt / 3;
      return std::max(replace, 3 - types);
    }
    int replace = 0, remove = n - 20;
    int remove2 = 0;
    int cnt = 0;
    char prev = '~';
    for (auto& curr: password) {
      if (curr == prev)
        ++cnt;
      else {
        if (remove > 0 and cnt >= 3) {
          if (cnt % 3 == 0) {
            --remove;
            --replace;
          } else if (cnt % 3 == 1)
            ++remove2;
        }
        replace += cnt / 3;
        cnt = 1;
        prev = curr;
      }
    }
    if (remove > 0 and cnt >= 3) {
      if (cnt % 3 == 0) {
        --remove;
        --replace;
      } else if (cnt % 3 == 1)
        ++remove2;
    }
    replace += cnt / 3;

    const int use2 = std::min({ remove2, remove / 2, replace });
    replace -= use2;
    remove -= use2 * 2;

    const int use3 = std::min(replace, remove / 3);
    replace -= use3;
    remove -= use3 * 3;
    return (n - 20) + std::max(replace, 3 - types);
  }
};
