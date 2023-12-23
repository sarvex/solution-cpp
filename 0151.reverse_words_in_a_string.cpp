#include <algorithm>
#include <sstream>
#include <vector>

class Solution {
public:
  auto reverseWords(const std::string& s) {
    std::istringstream stream (s);
    std::vector<std::string> strings;

    for (std::string token; stream >> token;) {
      strings.emplace_back(token);
    }

    std::ostringstream output;
    for (int i = strings.size() - 1; ~i; --i) {
      if (i) output << strings[i] << ' ';
      else output << strings[i];
    }
    return output.str();
  }
};
