#include <deque>
#include <sstream>
#include <string>

class Solution {
public:
  auto simplifyPath(const std::string& path) -> std::string {
    std::deque<std::string> stk;

    std::istringstream stream(path);
    for (std::string token; getline(stream, token, '/');) {
      if (token.empty() or token == ".") continue;
      if (token == "..") { if (not stk.empty()) stk.pop_back(); } else { stk.push_back(token); }
    }

    if (stk.empty()) return "/";
    std::ostringstream result;
    for (auto& s: stk) result << "/" + s;
    return result.str();
  }
};
