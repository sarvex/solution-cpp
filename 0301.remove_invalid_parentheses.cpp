#include <functional>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  auto removeInvalidParentheses(const std::string& s) -> std::vector<std::string> {
    std::unordered_set<std::string> result;
    int l = 0, r = 0;
    const auto n = s.size();
    for (auto& ch: s) { if (ch == '(') { ++l; } else if (ch == ')') { if (l) { --l; } else { ++r; } } }
    std::function<void(int, int, int, int, int, std::string)> search = [&
        ](const int i, const int l, const int r, const int lcnt, const int rcnt, const std::string& t) {
      if (i == n) {
        if (l == 0 and r == 0) result.insert(t);
        return;
      }
      if (n - i < l + r or lcnt < rcnt) { return; }
      if (s[i] == '(' and l) { search(i + 1, l - 1, r, lcnt, rcnt, t); }
      if (s[i] == ')' and r) { search(i + 1, l, r - 1, lcnt, rcnt, t); }
      const int x = s[i] == '(' ? 1 : 0;
      const int y = s[i] == ')' ? 1 : 0;
      search(i + 1, l, r, lcnt + x, rcnt + y, t + s[i]);
    };

    search(0, l, r, 0, 0, "");
    return { result.begin(), result.end() };
  }
};
