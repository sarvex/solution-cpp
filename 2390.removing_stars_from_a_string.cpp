#include <string>

class Solution {
public:
  auto removeStars(const std::string& s) {
    std::string result;
    for (auto& c: s) if (c == '*') result.pop_back(); else result.push_back(c);
    return result;
  }
};
