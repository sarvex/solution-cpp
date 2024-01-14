#include <string>
#include <vector>

class Solution {
public:
  bool canReach(const std::string& s, const int minJump, const int maxJump) {
    const auto n = s.size();
    std::vector pre(n + 1, 0);
    pre[1] = 1;
    std::vector result(n, false);
    result[0] = true;
    for (int i = 1; i < n; ++i) {
      if (s[i] == '0') {
        const int l = std::max(0, i - maxJump);
        const int r = i - minJump;
        result[i] = l <= r and pre[r + 1] - pre[l];
      }
      pre[i + 1] = pre[i] + result[i];
    }
    return result[n - 1];
  }
};
