#include <functional>
#include <string>
#include <vector>

class Solution {
public:
  auto generateParenthesis(const int n) {
    std::vector<std::string> result;

    std::function<void(int, int, std::string)> generate = [&](const int l, const int r, const std::string& t) {
      if (l > n or r > n or l < r) return;
      if (l == n and r == n) {
        result.push_back(t);
        return;
      }
      generate(l + 1, r, t + "(");
      generate(l, r + 1, t + ")");
    };

    generate(0, 0, "");
    return result;
  }
};
