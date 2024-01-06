#include <string>
#include <vector>

class Solution {
public:
  int numberOfBeams(const std::vector<std::string>& bank) {
    int result = 0;
    int last = 0;
    for (auto& b: bank) {
      int t = 0;
      for (auto& c: b)
        if (c == '1')
          ++t;
      if (t) {
        result += last * t;
        last = t;
      }
    }
    return result;
  }
};
