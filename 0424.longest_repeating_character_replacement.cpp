#include <string>
#include <vector>

class Solution {
public:
  int characterReplacement(const std::string& s, int k) {
    std::vector counter(26, 0);
    int i = 0, j = 0, count = 0;
    for (auto& c: s) {
      ++counter[c - 'A'];
      count = std::max(count, counter[c - 'A']);
      if (i - j + 1 > count + k) {
        --counter[s[j] - 'A'];
        ++j;
      }
      ++i;
    }
    return i - j;
  }
};
