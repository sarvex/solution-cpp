#include <functional>
#include <string>
#include <vector>

class Solution {
public:
  static std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    std::function<void(int, int, std::string)>
    dfs = [&](const int l, const int r, const std::string& t) {
      if (l > n or r > n or l < r) return;
      if (l == n and r == n) {
        result.push_back(t);
        return;
      }
      dfs(l + 1, r, t + "(");
      dfs(l, r + 1, t + ")");
    };
    dfs(0, 0, "");
    return result;
  }
};
