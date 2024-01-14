#include <string>
#include <vector>

class Solution {
public:
  auto minSteps(const std::string& s, const std::string& t) {
    std::vector count(26, 0);
    for (auto& c: s) ++count[c - 'a'];
    int result = 0;
    for (auto& c: t) { result += --count[c - 'a'] < 0; }
    return result;
  }
};
