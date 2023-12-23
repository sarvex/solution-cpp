#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  bool wordPattern(const std::string& pattern, const std::string& s) {
    std::istringstream stream(s);
    std::vector<std::string> tokens;
    for (std::string token; stream >> token;) { tokens.push_back(token); }
    if (pattern.size() != tokens.size()) { return false; }
    std::unordered_map<char, std::string> d1;
    std::unordered_map<std::string, char> d2;
    for (int i = 0; i < tokens.size(); ++i) {
      char a = pattern[i];
      std::string b = tokens[i];
      if ((d1.contains(a) and d1[a] != b) or (d2.contains(b) and d2[b] != a)) { return false; }
      d1[a] = b;
      d2[b] = a;
    }
    return true;
  }
};
