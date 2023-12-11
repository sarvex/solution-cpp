#include <functional>
#include <string>
#include <vector>

using std::function;
using std::string;
using std::vector;

class Solution {
public:
  auto generateParenthesis(const int n) {
    vector<string> result;

    function<void(int, int, string)>
    dfs = [&](const int l, const int r, const string& t) {
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
