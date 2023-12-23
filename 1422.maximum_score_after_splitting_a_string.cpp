#include <algorithm>
#include <string>

class Solution {
public:
  int maxScore(const std::string& s) {
    int count = 0;
    if (s[0] == '0') ++count;
    for (int i = 1; i < s.size(); ++i) count += s[i] == '1';
    int result = count;
    for (int i = 1; i < s.size() - 1; ++i) {
      count += s[i] == '0' ? 1 : -1;
      result = std::max(result, count);
    }
    return result;
  }
};
