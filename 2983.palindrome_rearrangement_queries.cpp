#include <algorithm>
#include <functional>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<bool> canMakePalindromeQueries(std::string& s, const std::vector<std::vector<int>>& queries) {
    const int n = s.length(), m = n / 2;
    auto t = std::string(s.begin() + m, s.end());
    reverse(t.begin(), t.end());
    s = std::string(s.begin(), s.begin() + m);

    std::vector pre1(m + 1, std::vector<int>(26));
    std::vector pre2(m + 1, std::vector<int>(26));
    std::vector diff(m + 1, 0);

    const std::function<std::vector<int>(std::vector<std::vector<int>>, int, int)> count = [&
        ](const std::vector<std::vector<int>>& pre, const int i, const int j) {
      std::vector result(26, 0);
      for (int k = 0; k < 26; ++k) { result[k] = pre[j + 1][k] - pre[i][k]; }
      return result;
    };

    const std::function<std::vector<int>(std::vector<int>, std::vector<int>)> sub = [&
        ](const std::vector<int>& cnt1, const std::vector<int>& cnt2) -> std::vector<int> {
      std::vector result(26, 0);
      for (int i = 0; i < 26; ++i) {
        result[i] = cnt1[i] - cnt2[i];
        if (result[i] < 0) return {};
      }
      return result;
    };

    const std::function<bool(
        std::vector<std::vector<int>>,
        std::vector<std::vector<int>>,
        std::vector<int>,
        int,
        int,
        int,
        int)> check = [&](
        const std::vector<std::vector<int>>& first,
        const std::vector<std::vector<int>>& second,
        const std::vector<int>& result,
        const int a,
        const int b,
        const int c,
        const int d) {
      if (result[a] > 0 or result[result.size() - 1] - result[std::max(b, d) + 1] > 0) return false;
      if (d <= b) return count(first, a, b) == count(second, a, b);
      if (b < c)
        return result[c] - result[b + 1] == 0 and count(first, a, b) == count(second, a, b)
               and count(first, c, d) == count(second, c, d);

      const std::vector<int> cnt1 = sub(count(first, a, b), count(second, a, c - 1));
      const std::vector<int> cnt2 = sub(count(second, c, d), count(first, b + 1, d));

      return not cnt1.empty() and not cnt2.empty() and cnt1 == cnt2;
    };

    for (int i = 1; i <= m; ++i) {
      pre1[i] = pre1[i - 1];
      pre2[i] = pre2[i - 1];
      ++pre1[i][s[i - 1] - 'a'];
      ++pre2[i][t[i - 1] - 'a'];
      diff[i] = diff[i - 1] + (s[i - 1] == t[i - 1] ? 0 : 1);
    }

    std::vector<bool> ans(queries.size(), false);
    for (int i = 0; i < queries.size(); ++i) {
      std::vector<int> q = queries[i];
      const int a = q[0], b = q[1], c = n - 1 - q[3], d = n - 1 - q[2];
      ans[i] = (a <= c) ? check(pre1, pre2, diff, a, b, c, d) : check(pre2, pre1, diff, c, d, a, b);
    }
    return ans;
  }
};
